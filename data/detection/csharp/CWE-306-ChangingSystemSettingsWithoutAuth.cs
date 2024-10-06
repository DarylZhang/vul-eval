using System;

class SystemSettings
{
    static void Main(string[] args)
    {
        string systemUser = "guest";
        int brightnessLevel = 80;

        UpdateSettings(systemUser, brightnessLevel);

        ExtraDummyLogic();
    }

    static void UpdateSettings(string user, int brightness)
    {
        //CWE-306
        SetBrightness(brightness);

        ExecuteOtherTasks();
    }

    static void SetBrightness(int level)
    {
        Console.WriteLine("Brightness set to " + level);
    }

    static void ExtraDummyLogic()
    {
        for (int i = 0; i < 100; i++)
        {
            PerformAnotherDummyMethod(i);
        }
    }

    static void ExecuteOtherTasks()
    {
        Console.WriteLine("Executing various system tasks...");
    }

    static void PerformAnotherDummyMethod(int i)
    {
        if (i % 2 == 0)
        {
            Console.WriteLine("Performing even-numbered task: " + i);
        }
        else
        {
            Console.WriteLine("Performing odd-numbered task: " + i);
        }
    }
}