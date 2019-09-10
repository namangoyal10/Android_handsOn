import java.util.*;

class mgo
  { public static  void main(String args[])  
     {
        int[] arr=new int[10] ;
	String[] arrc=new String[10];
  
        for(int i=0;i<=9;i++)
	   {     Scanner sc=new Scanner(System.in);
		 System.out.println("enter value");
		 arr[i]=sc.nextInt();
           }  

 System.out.println("\n");

  for(int i=0;i<=9;i++)
	   {     Scanner aa=new Scanner(System.in);
		 System.out.println("enter value");
		 arrc[i]=aa.next();
           }  

 System.out.println("\n");
 for(int i=0;i<=9;i++)
	   {     
		 System.out.println(+arr[i]);
		 
           }     
       System.out.println("\n");
 for(int i=0;i<=9;i++)
	   {     
		 System.out.println(" "+arrc[i]);
		 
           }
 System.out.println("\n"); 
} 
    } 