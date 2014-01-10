//

using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Threading;
using System.Diagnostics;
using System.Globalization;
using System.Text.RegularExpressions;
using System.Linq;

namespace sar_cs
{
    static class Helpers
    {
        public static string Join<T>(this IEnumerable<T> objs, string sep)
        {
            var sb = new StringBuilder();
            foreach (var s in objs) { if (sb.Length != 0) sb.Append(sep); sb.Append(s); }
            return sb.ToString();
        }

        public static string AsString(this double a, int digits)
        {
            return a.ToString("F" + digits, CultureInfo.InvariantCulture);
        }

        public static T[] Copy<T>(this T[] a)
        {
            var b = new T[a.Length]; a.CopyTo(b, 0); return b;
        }

        public static T[][] Copy<T>(this T[][] a)
        {
            return a.Select(z => z.Copy()).ToArray();
        }

        public static IEnumerable<T> Shuffle<T>(this IEnumerable<T> collection)
        {
            if (collection.Take(11).Count() <= 10) return collection;
            var a = collection is T[] ? (T[])collection : collection.ToArray();
            int N = a.Length;
            for (int i = 0, p1 = 0, p2 = 1; i < N / 2; i++)
            {
                p1 += 3; if (p1 >= N) p1 -= N;
                p2 -= 7; if (p2 < 0) p2 += N;
                T t = a[p1]; a[p1] = a[p2]; a[p2] = t;
            }
            return a;
        }

        public static string AsString<T>(this T[,] a, string separator)
        {
            var sb = new StringBuilder();
            int n0 = a.GetLength(0);
            int n1 = a.GetLength(1);
            for (int r = 0; r < n0; r++)
            {
                for (int c = 0; c < n1; c++)
                {
                    if (c != 0) sb.Append(separator); sb.Append(a[r, c]);
                }
                sb.AppendLine();
            }
            //sb.AppendLine();
            return sb.ToString();
        }

        public static Stopwatch SW = Stopwatch.StartNew();
    }

    public class Program
    {
        #region Helpers

        public class Parser
        {
            const int BufSize = 8000;
            TextReader s;
            char[] buf = new char[BufSize];
            int bufPos;
            int bufDataSize;
            bool eos;   // eos read to buffer
            int lastChar = -2;
            int nextChar = -2;
            StringBuilder sb = new StringBuilder();

            void FillBuf()
            {
                if (eos) return;
                bufDataSize = s.Read(buf, 0, BufSize);
                if (bufDataSize == 0) eos = true;
                bufPos = 0;
            }

            int Read()
            {
                if (nextChar != -2)
                {
                    lastChar = nextChar;
                    nextChar = -2;
                }
                else
                {
                    if (bufPos == bufDataSize) FillBuf();
                    if (eos) lastChar = -1; else lastChar = buf[bufPos++];
                }
                return lastChar;
            }

            void Back()
            {
                if (lastChar == -2) throw new Exception();  // no chars were ever read
                nextChar = lastChar;
            }

            public Parser()
            {
                s = Console.In;
            }

            public int ReadInt()
            {
                int res = 0;
                int sign = -1;
                int c;
                do { c = Read(); } while (c >= 0 && char.IsWhiteSpace((char)c));
                if (c == '-') { sign = 1; c = Read(); }
                int len = 0;
                while (c >= 0 && !char.IsWhiteSpace((char)c))
                {
                    if ((uint)(c -= 48) >= 10) throw new FormatException();
                    len++;
                    res = checked(res * 10 - c);
                    c = Read();
                }
                if (len == 0) throw new FormatException();
                Back();
                return checked(res * sign);
            }

            public long ReadLong()
            {
                long res = 0;
                int sign = -1;
                int c;
                do { c = Read(); } while (c >= 0 && char.IsWhiteSpace((char)c));
                if (c == '-') { sign = 1; c = Read(); }
                int len = 0;
                while (c >= 0 && !char.IsWhiteSpace((char)c))
                {
                    if ((uint)(c -= 48) >= 10) throw new FormatException();
                    len++;
                    res = checked(res * 10 - c);
                    c = Read();
                }
                if (len == 0) throw new FormatException();
                Back();
                return checked(res * sign);
            }

            public int ReadLnInt()
            {
                int res = ReadInt(); ReadLine(); return res;
            }

            public long ReadLnLong()
            {
                long res = ReadLong(); ReadLine(); return res;
            }

            public double ReadDouble()
            {
                int c;
                do { c = Read(); } while (c >= 0 && char.IsWhiteSpace((char)c));

                int sign = 1;
                if (c == '-') { sign = -1; c = Read(); }

                sb.Length = 0;
                while (c >= 0 && !char.IsWhiteSpace((char)c))
                {
                    sb.Append((char)c); c = Read();
                }

                Back();
                var res = double.Parse(sb.ToString(), CultureInfo.InvariantCulture);
                return res * sign;
            }

            public string ReadLine()
            {
                int c = Read();
                sb.Length = 0;
                while (c != -1 && c != 13 && c != 10)
                {
                    sb.Append((char)c); c = Read();
                }
                if (c == 13) { c = Read(); if (c != 10) Back(); }
                return sb.ToString();
            }

            public bool SeekEOF
            {
                get
                {
                L0:
                    int c = Read();
                    if (c == -1) return true;
                    if (char.IsWhiteSpace((char)c)) goto L0;
                    Back();
                    return false;
                }
            }

            public int[] ReadIntArr(int n)
            {
                var a = new int[n]; for (int i = 0; i < n; i++) a[i] = ReadInt(); return a;
            }

            public long[] ReadLongArr(int n)
            {
                var a = new long[n]; for (int i = 0; i < n; i++) a[i] = ReadLong(); return a;
            }
        }

        class Writer
        {
            const int BufSize = 32000;
            char[] buf = new char[BufSize];
            int bufPos = 0;
            TextWriter output = Console.Out;
            Stack<char> st = new Stack<char>();

            public void Flush()
            {
                output.Write(buf, 0, bufPos); bufPos = 0;
                output.Flush();
            }

            void BufSpaceNeeded(int n)
            {
                if (n > BufSize) throw new ArgumentOutOfRangeException("n");
                if (bufPos + n > BufSize) { output.Write(buf, 0, bufPos); bufPos = 0; }
            }

            public void Write(char a)
            {
                BufSpaceNeeded(1);
                buf[bufPos++] = a;
            }

            public void Write(string s)
            {
                int l = s.Length;
                for (int x = 0; x < l; )
                {
                    int t = Math.Min(l - x, BufSize - bufPos);
                    s.CopyTo(x, buf, bufPos, t); bufPos += t; x += t;
                    if (x < l) BufSpaceNeeded(1);   // force flush
                }
            }

            public void WriteLine()
            {
                BufSpaceNeeded(2);
                buf[bufPos++] = '\r'; buf[bufPos++] = '\n';
            }

            public void Write(object o) { Write(o.ToString()); }

            public void Write(uint a)
            {
                BufSpaceNeeded(10);
                do { st.Push((char)(a % 10 + 48)); a /= 10; } while (a != 0);
                while (st.Count != 0) buf[bufPos++] = st.Pop();
            }

            public void Write(ulong a)
            {
                BufSpaceNeeded(20);
                do { st.Push((char)(a % 10 + 48)); a /= 10; } while (a != 0);
                while (st.Count != 0) buf[bufPos++] = st.Pop();
            }

            public void Write(int a)
            {
                BufSpaceNeeded(11);
                if (a < 0) { buf[bufPos++] = '-'; a = -a; }
                Write((uint)a);
            }

            public void Write(long a)
            {
                BufSpaceNeeded(21);
                if (a < 0) { buf[bufPos++] = '-'; a = -a; }
                Write((ulong)a);
            }

            public void Write(double a, int digits)
            {
                Write(a.AsString(digits));
            }

            public void WriteLine(int a) { Write(a); WriteLine(); }
            public void WriteLine(long a) { Write(a); WriteLine(); }
            public void WriteLine(uint a) { Write(a); WriteLine(); }
            public void WriteLine(ulong a) { Write(a); WriteLine(); }
            public void WriteLine(string s) { Write(s); WriteLine(); }
            public void WriteLine(object o) { Write(o); WriteLine(); }
        }

        static void pe() { Console.WriteLine("???"); Environment.Exit(0); }
        static void re() { throw new Exception(); }
        static void Swap<T>(ref T a, ref T b) { T t = a; a = b; b = t; }
        static int Sqr(int a) { return a * a; }
        static long SqrL(int a) { return (long)a * a; }
        static long Sqr(long a) { return a * a; }
        static double Sqr(double a) { return a * a; }
        static double Sqrt(double a) { return Math.Sqrt(a); }

        static StringBuilder sb = new StringBuilder();
        static Random rnd = new Random(5);

        #endregion Helpers

        static void Main()
        {
            checked
            {
#if !ONLINE_JUDGE
                Console.SetIn(File.OpenText("_input"));
#endif
                //Console.SetOut(File.CreateText("_output"));
                var parser = new Parser();
                var o = new Writer();
                try
                {
                    while (!parser.SeekEOF)
                    {
                        int n = parser.ReadInt();
                        int m = parser.ReadInt();
                        var a = parser.ReadIntArr(1 << n);

                        var nodes = new int[n + 1][];
                        nodes[n] = a;
                        bool xor = false;
                        for (int i = n - 1; i >= 0; i--)
                        {
                            nodes[i] = new int[1 << i];
                            for (int j = 0; j < 1 << i; j++)
                                nodes[i][j] = xor
                                    ? nodes[i + 1][j * 2] ^ nodes[i + 1][j * 2 + 1]
                                    : nodes[i + 1][j * 2] | nodes[i + 1][j * 2 + 1];

                            xor = !xor;
                        }

                        for (int ii = 0; ii < m; ii++)
                        {
                            var p = parser.ReadInt() - 1;
                            var q = parser.ReadInt();

                            xor = false;
                            nodes[n][p] = q;
                            int j = p / 2;
                            for (int i = n - 1; i >= 0; i--, j /= 2, xor = !xor)
                                nodes[i][j] = xor
                                    ? nodes[i + 1][j * 2] ^ nodes[i + 1][j * 2 + 1]
                                    : nodes[i + 1][j * 2] | nodes[i + 1][j * 2 + 1];

                            o.WriteLine(nodes[0][0]);
                        }

                    }
                }
                finally
                {
                    o.Flush();
                }
            }
        }

        //static void Main()
        //{
        //    new Thread(Main2, 50 << 20).Start();
        //}
    }
}