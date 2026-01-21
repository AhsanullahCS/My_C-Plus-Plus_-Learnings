#include<iostream>
using namespace std;

struct Items
{
    string item;
    int    price;
    int    quantity;
};

struct Cart
{
    string item;
    int    price;
    int    quantity;
};

// Function 1 see items
void Seeitems(const Items item[] , int size)
{
    cout<<" AVAILABLE ::>> "<<size<<" <<::ITEMS IN THE STORE"<<endl;
    cout<<left<<"No"<<"   "<<"NAME"<<"   "<<"PRICE"<<"   "<<"QUANTITY"<<endl;

    for(int i=0; i<size; i++)
    {
        cout<<left<<i+1<<"   "<<item[i].item<<"   "<<item[i].price<<"   "<<item[i].quantity<<endl;
    }
}

// function 2 add to cart
void addtocart( Items item[] , int size , Cart max[] , int &CartCount)
{
    int itemnumber , quan ;
    cout<<"ENTER THE ITEM NO TO ADD "<<endl;
    cin>>itemnumber;
    cout<<"ENTER THE VALID QUANTITY"<<endl;  
    cin>>quan;

     int i = itemnumber - 1;
     if(quan > item[i].quantity || CartCount > 20)
     {
        cout<<"iNVALID TRY AGAIN"<<endl;    
        return;
     }
      max[CartCount].item = item[i].item;
      max[CartCount].price = item[i].price;
      max[CartCount].quantity = quan; // user input
      CartCount++;  // update count
        
      item[i].quantity-=quan;
      
        cout<<"THE ITEM NO::"<<i+1<<"::"<<item[i].item<<"::OF QUANTITY::"<<quan<<"::IS ADDED TO YOUR CART"<<endl;
}

//Function 3
void viewcart(int &Cartcount , Cart max[])
{
    cout<<"YOUR CART HAVE>>::"<<Cartcount<<"::<<"<<"ITEMS"<<endl;
    cout<<left<<"No"<<"   "<<"NAME"<<"   "<<"PRICE"<<"   "<<"QUANTITY"<<endl;

    for(int i=0; i<Cartcount; i++)
    {
    cout<<left<<i+1<<"   "<<max[i].item<<"   "<<max[i].price<<"   "<<max[i].quantity<<endl;
    }
}

//function 4
void checkout(int cartcount , Cart max[])
{
    int total = 0;

    for (int i=0; i<cartcount; i++)
    {
         total += max[i].price * max[i].quantity;
    }
    cout<<"THE TOTAL AMOUNT YOU HAVE TO PAY IS ::>>"<<total<<endl;
}

int main()
{
    Items item[] =   {
        //array of structures; 
        {"APPLE" , 100 , 50},
        {"ORANGE" , 100 , 50},
        {"BANANA" , 100 , 50},
        {"FRUIT" , 100 , 50},
    };
    int size  =  sizeof(item) / sizeof(item[0]);

    Cart max [20];
    int CartCount = 0;

    int choic;
    string choice;
    do
    {
        cout<<" PRESS 1 TO SEE ITEMS "<<endl;
        cout<<" PRESS 2 TO ADD TO CART"<<endl;
        cout<<" PRESS 3 TO VIEW CART "<<endl;
        cout<<" PRESS 4 TO CHECK OUT "<<endl;
        cin>>choic;

        switch (choic)
        {
        case 1:
        Seeitems(item , size);
        break;

        case 2:
        addtocart(item , size , max , CartCount);    
        break;

        case 3:
        viewcart(CartCount , max);
        break;

        case 4:
        checkout(CartCount  , max);
        break;
        
        default:
        cout<<"INVALID CHOICE"<<endl;
         break;
        }

     cout<<"DO YOU WANT TO CONTINUE PRESS *Y* AND FOR NO PRESS *N* "<<endl;
     cin>>choice;

    } while (choice == "y" && choice != "n");

return 0;
}
