using System;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;

[Serializable]
class CustomObject
{
    public string Name { get; set; }
    public int Value { get; set; }
}

class ComplexHandler
{
    private int dummyValue1;
    private string dummyValue2;

    public ComplexHandler(int val1, string val2)
    {
        dummyValue1 = val1;
        dummyValue2 = val2;
    }

    public bool ProcessDummyLogic(CustomObject obj)
    {
        if (dummyValue1 > 100)
        {
            DummyMethod1(obj.Name);
        }
        else
        {
            DummyMethod2(dummyValue2);
        }
        return true;
    }

    private void DummyMethod1(string data)
    {
        for (int i = 0; i < 10; i++)
        {
            Console.WriteLine("Processing: " + data);
        }
    }

    private void DummyMethod2(string data)
    {
        Console.WriteLine("Executing DummyMethod2 with " + data);
    }

    public void PerformComplexTask(Stream inputStream)
    {
        DummyValidator();

        BinaryFormatter formatter = new BinaryFormatter();
        CustomObject deserializedObj = (CustomObject)formatter.Deserialize(inputStream);

        if (ProcessDummyLogic(deserializedObj))
        {
            Console.WriteLine("Logic processed");
        }
    }

    private void DummyValidator()
    {
        if (dummyValue1 % 2 == 0)
        {
            Console.WriteLine("Validation passed");
        }
        else
        {
            Console.WriteLine("Validation failed");
        }
    }
}

class Program
{
    static void Main(string[] args)
    {
        string dummyInput = "Some complex input";
        int dummyValue = 150;

        ComplexHandler handler = new ComplexHandler(dummyValue, dummyInput);
        using (FileStream fs = new FileStream("data.bin", FileMode.Open))
        {
            handler.PerformComplexTask(fs);
        }
    }
}