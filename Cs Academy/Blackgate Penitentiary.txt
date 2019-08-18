// Don't place your source in a package
import java.util.*;
import java.lang.*;
import java.io.*;

// Please name your class Main
class Main {
public static void main (String[] args) throws java.lang.Exception {
	    
	    Map<Integer,List<String>> hm = new HashMap<Integer,List<String>>();
	    Scanner in = new Scanner(System.in); 
		int n = in.nextInt(); //קליטת מס חברים

		for (int i=0; i<n; i++){ //הכנסת חברים
		    String s = in.next(); // קליטת שם חבר 
		    int    h = in.nextInt(); // קליטת מספר מתאים לחבר 
	
	        // עדכון ה hash map 
	        // בודקים יש במפה מפתח במספר של חבר הקבוצה
	        if (hm.containsKey(h))    //if (hm.key==h  exist)
	        { 
	            List<String> nameList =new ArrayList<String>();
	            nameList  = hm.get(h); //אם יש אז לוקחים את הרשימת שמות במספר הזה   
	            nameList.add(s);//מוסיפים ה את השם של החבר הנוכחי 
	            hm.put(h,nameList);//מעדכנים את המפה
	        }     
	   
            else { //אם לא קיים בערך הזה רשימה של חברים במפה
                List<String> nameList = new ArrayList<String>();
                nameList.add(s);//יוצרים רשימה שמים בה את השם של החבר הנוכחי ואתה נכניס למפה 
                hm.put(h,nameList); 
            }
 		}
            
    	  
	    
	   Map<Integer, List<String>> hms = new TreeMap<Integer, List<String>> (hm);
	   
	   
	   //count  על מנת לספור באיזה חבר אנחנו 
	   
	    int count=0;
	    //עוברים על המפה 
	   for(Map.Entry  m:hms.entrySet()){
	   
    	   List<String> nameList = (ArrayList<String>)m.getValue();
    	   Collections.sort(nameList);//ממינים את רשימת השמות לכל מפתח 
           for(int i=0; i<nameList.size(); i++)//מדפיסים את השמות ברשימה
                    System.out.print(nameList.get(i)+" ");
    	   //מספר החבר הראשון והחבר האחרון 
    	   System.out.println((++count)+" "+(count+nameList.size()-1));
    	   //מעדכנים את count
    	   count+= nameList.size()-1;
	       
	   }
	}
} 
