import java.util.*;

  class std 
      {   int age,roll;
	  String name;
	  
	void input()
	    {  Scanner sc=new Scanner(System.in);	
		System.out.print("Enter the roll no.");
		roll=sc.nextInt();
		System.out.print("Enter the name");
		name=sc.next();
		System.out.print("Enter the age");
		age=sc.nextInt();
	    }
	}

    class group 	
      { int id;
	 void output()
	    {  Scanner sc=new Scanner(System.in);	
		System.out.print("Enter the id.");
		id=sc.nextInt();
	    } 
      } 

   class net
	{ public static void main(String args[])		
		{ 
  			std s=new std();
		  	s.input();
	
			group g=new group();
			g.output();

			if(s.roll==g.id)

			    {	System.out.print("salary=120000");
			    }
			else	
			    {   System.out.print("roll no. mismatch");
			    }
		}
	}