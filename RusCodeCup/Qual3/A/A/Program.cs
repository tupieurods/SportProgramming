using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace A
{
  class Program
  {
    static void Main(string[] args)
    {
      int n;
      string[] line = Console.ReadLine().Split(' ');
      n = Int32.Parse(line[0]);
      string[] dateTime;
      for(int i = 0; i < n; i++)
      {
        line = Console.ReadLine().Split(' ');
        dateTime = line[0].Split(':');
        DateTime start = new DateTime(1933, 1, 17,
          Int32.Parse(dateTime[0]), Int32.Parse(dateTime[1]), Int32.Parse(dateTime[2]));
        dateTime = line[1].Split(':');
        DateTime end = new DateTime(1933, 1, 17,
          Int32.Parse(dateTime[0]), Int32.Parse(dateTime[1]), Int32.Parse(dateTime[2]));
        if(end <= start)
        {
          end = end.AddDays(1);
        }
        int len = (int)((end - start).TotalMinutes);
        int delta = Int32.Parse(line[2]);
        if(len >= delta)
        {
          Console.WriteLine("Perfect");
        }
        else if(len + 60 >= delta)
        {
          Console.WriteLine("Test");
        }
        else
        {
          Console.WriteLine("Fail");
        }
      }
    }
  }
}
