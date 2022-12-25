/*Program for resturant order payment application.*/
#include<iostream>
using namespace std;
int main (){	
//output of menu	
cout<<"code       meal           per kg price in pakistani rupees"<<endl;
cout<<" 1      chiken handi                 1800                 "<<endl;
cout<<" 2      chiken karahi                2000                 "<<endl;
cout<<" 3      chiken tikka                 2200                 "<<endl;
cout<<" 4      chiken haleem                500                  "<<endl;
cout<<" 5      creamy chiken                2500                 "<<endl;
cout<<"*****************************************************************"<<endl; 
//declaring integars.
int x;
double y;
int r;
double meal_price;
double sale_tax;
double total_amount;
int dollar=165;
int euro=193;
//Output for asking which choice the user wants to select.
cout<<"Please enter your choice: "; cin>>x;
cout<<endl;
cout<<"*****************************************************************"<<endl;
//displaying error if the user enters invalid code.
if (x<=0 || x>5){	cout<<"error ";	cout<<endl;
	return 0;
}
//Output for displaying the qantity of the product.
else if (x>0 && x<=5){	cout<<"Enter the quantity in kgs: "; cin>>y;
	cout<<endl;	
cout<<"*****************************************************************"<<endl;
//Output of meal price if the user selects a code between 1 and 5.
if (x==1){	meal_price=y*1800;
}
else if (x==2){	meal_price=y*2000;
}
else if (x==3){	meal_price=y*2200;	
}
else if (x==4){	meal_price=y*500;
}
else if (x==5){	meal_price=y*2500;
}
}
//Displaying error if the user enters an invalid quantity.
 if (y<=0){cout<<"error ";
	cout<<endl;
} 
//Asking the user in which currency he/she wants to pay.
else if (y>0){	cout<<"Please enter the currency you want to pay: "<<"1 for rupees, "<<"2 for dollar, "<<"3 for euro: ";cin>>r;	
}
//Displaying error if the user enters an invalid currency. 
	if(r!=1 && r!=2 && r!=3){	
	cout<<"error"<<endl;
	cout<<endl;
	cout<<"*************************************************************"<<endl;	
}
else { 
//If the meal price is below 1000 then there will be no sale tax.
if (meal_price <=1000){	total_amount=meal_price;
	sale_tax=0;
}
//If the meal price is greater than 1000 but less than 3000 then the sale tax wil be 2%
else if (meal_price>1000 && meal_price<=3000){	
 sale_tax=meal_price*0.02;
 total_amount=meal_price+sale_tax;	
}
//If the meal price is greater than 3000 than the sale tax will be 5%.
else if (meal_price>3000){
	sale_tax=meal_price*0.05;
	total_amount=meal_price+sale_tax;
}
//Displaying total amount, sale tax and meal price in dollars if the user enters 2.
if (r==2){	total_amount=total_amount/dollar;
		sale_tax=sale_tax/dollar;
		meal_price=meal_price/dollar;
		cout<<"meal price: $ "<<meal_price<<endl;
		cout<<"sale tax:$ "<<sale_tax<<endl;
cout<<"total amount to be paid:$ "<<total_amount<<endl;}
//Displaying total amount, sale tax and meal price in euro if the user enters 3.	
	if (r==3){		
		total_amount=total_amount/euro;
		sale_tax=sale_tax/euro;
		meal_price=meal_price/euro;
		cout<<"meal price: €"<<meal_price<<endl;
		cout<<"sale tax: €"<<sale_tax<<endl;
cout<<"total amount to be paid: €  "<<total_amount<<endl;		
}
//Displaying total amount, sale tax and meal price in pkr rupees if the user enters 1.
if (r==1){	
cout<<"meal price: Rs "<<meal_price<<endl;
cout<<"sale tax: Rs "<<sale_tax<<endl;
cout<<"total amount to be paid: Rs "<<total_amount<<endl;
}
}
system ("pause");
return 0;
}
