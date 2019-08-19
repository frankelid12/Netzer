
using System;
using System.Linq;
using System.Collections.Generic;
using System.Collections;
//הבעיה משטח משבצות גדול שקיימות בו כמה שכבות חלק מוסיפות +1 למשבצות וחלק -1 ועילנו עבור איזשהו שטח לחשב את סכום המשבצות
//נבנה מערך של שכבות שכל שכבה מוגדרת על ידי פעולה (חיבור או חיסור או תוצאה) ושתי נקודות שמגידרות את גודל הריבוע (אלכסון)
namespace Solution
{
    public class MainClass
    {
        public static void Main()
        {
            // Read dimensions - Not used.
            Console.ReadLine().Split(' ');

            // Create the list of layers.
            List<Layer> layers = new List<Layer>();

            // Get number of queries
            int numQueries = Convert.ToInt32(Console.ReadLine());
            for (int i = 0; i < numQueries; i++) {
                Query query = Query.FromString(Console.ReadLine());
                ProcessQuery(layers, query);
            }
        }

        private static void ProcessQuery(List<Layer> layers, Query query)
        {
            //עיבוד השאילתה במקרה וזה הוספה או הסרה הוסף למערך
            switch (query.Operation) {
            case Operations.Add:
            case Operations.Remove:
                layers.Add(query.Layer);
                break;

                    //במקרה וזה תוצאה חשב את השכבות המצויות במערך על ידי הפונקציה למטה
            case Operations.Question:
                ShowLayer(layers, query.Layer);
                break;
            }
        }
        //  פנוקציה של התוצאה - רץ על כל השכבות שקיימות מחשב עבור ריבוע של תוצאה את שטח החיתוך שלו עם כל שכבה מסוימת מכפיל בפעולה (1/-1)
        private static void ShowLayer(List<Layer> layers, Layer queryLayer)
        {
            int count = 0;
            //
            foreach (Layer layer in layers)
                count += layer.Value * layer.IntersectedArea(queryLayer);

            Console.WriteLine(count);
        }
    }

    //שכבה שמוגדרת על ידי ערך ההכפלה - כלומר הפעולה אם זה הוספה אז 1 אם זה הסרה אז -1 ואם זה תוצאה אז 0
    //שכבה מוגדרת גם משתי נקודות שמגדירות את הריבוע
    public class Layer
    {
        public Layer(int value, Point start, Point end)
        {
            Value = value;
            Start = start;
            End = end;
        }

        public int Value {
            get;
            set;
        }

        //תכונות סתם גטים וסטים
        public int Left {
            get { return Start.X; }
        }

        public int Right {
            get { return End.X; }
        }

        public int Top {
            get { return Start.Y; }
        }

        public int Bottom {
            get { return End.Y; }
        }

        public Point Start {
            get;
            private set;
        }

        public Point End {
            get;
            private set;
        }

        //האם השכבה לא נמצאת בתוך הריבוע שאנחנו בודקים את התוצאה שלו  
        //זה יעיל מכיוון ואם יש שאילתה של תוצאה שבכלל לא נוגעת לריבוע הזה אז הוא מדלג על חישוב מיותר
        public bool Intersect(Layer rect)
        {
            //מצדדיו או מעליו או מתחתיו
            return this.Left <= rect.Right && this.Right >= rect.Left &&
                this.Top <= rect.Bottom && this.Bottom >= rect.Top;
        }

        //תחילה עושה בדיקה האם הוא בכלל בתוך השטח ואז אם כן הוא מחפש את השטח של החיתוך ולאחר מכן מחשב את כמות המשבצות שמצויות בתוך השטח
        public int IntersectedArea(Layer rect)
        {
            if (!Intersect(rect))
                return 0;

            int intersectedLeft   = Math.Max(this.Left, rect.Left);
            int intersectedRight  = Math.Min(this.Right, rect.Right);
            int intersectedTop    = Math.Max(this.Top, rect.Top);
            int intersectedBottom = Math.Min(this.Bottom, rect.Bottom);
            return (intersectedRight - intersectedLeft   + 1) *
                (intersectedBottom - intersectedTop + 1);
        }

        public override string ToString()
        {
            return string.Format("[Layer: Value={0}, Start={1}, End={2}]", Value, Start, End);
        }
    }

    //שאילתה - כלומר מה הפעולה על השטח והשטח מוגדר על ידי שתי נקודות 
    public class Query
    {
        public Query(Operations operation, Point start, Point end)
        {
            Operation = operation;
            Start = start;
            End = end;
        }

        public Operations Operation {
            get;
            private set;
        }

        public Point Start {
            get;
            private set;
        }

        public Point End {
            get;
            private set;
        }

        //בניית שכבה עבור שאילתה (הוספה/הסרה/תוצאה)
        public Layer Layer {
            get {
                return new Layer((int)Operation, Start, End);
            }
        }

        //פרסור המידע - ממחרוזת לאובייקט
        public static Query FromString(string data)
        {
            string[] args = data.Split(' ');

            //אתחול ראשוני של הוספה ולאחרמכן לפי השורה מה הפעולה הנבחרת
            Operations operation = Operations.Add;
            switch (args[0]) {
            case "a":
                operation = Operations.Add;
                break;

            case "r":
                operation = Operations.Remove;
                break;

            case "q":
                operation = Operations.Question;
                break;
            }

            //יצירת הנקודה מתוך ההשורת קלט
            Point start = new Point(
                              Convert.ToInt32(args[2]) - 1,
                              Convert.ToInt32(args[1]) - 1);
            Point end = new Point(
                Convert.ToInt32(args[4]) - 1,
                Convert.ToInt32(args[3]) - 1);
            //יצירת אובקייט מסוג שאילתה
            return new Query(operation, start, end);
        }
  
        //סתם toString לצורך הבנה של הקוד שכתבנו
        public override string ToString()
        {
            return string.Format("[Query: Operation={0}, Start={1}, End={2}]", Operation, Start, End);
        }
    }

    //ENUM שמגדיר מה הפעולה האם אנחנו בחיבור בחיסור או בתוצאה
    public enum Operations {
        Add = 1,
        Remove = -1,
        Question = 0
    }

    //אובקייט מסוג נקודה 

    //עוזר לבניית הריבוע על ידי שתי נקודות שמבטאות את האלכסונים
    public class Point
    {
        public Point(int x, int y)
        {
            X = x;
            Y = y;
        }

        public int X {
            get;
            private set;
        }

        public int Y {
            get;
            private set;
        }

        public override string ToString()
        {
            return string.Format("[Point: X={0}, Y={1}]", X, Y);
        }
    }
}
