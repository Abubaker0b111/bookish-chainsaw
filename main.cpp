#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

// General functions

void encryptmessage(char[], char[]);
void decryptmessage(char[], char[]);
char encryptchar(char, char);
char decryptchar(char, char);

//Function for customer

bool hasUpperCase(char[]);
bool hasDigit(char[]);
void secureShop();
void regster(char[]);
void customerChoice();
bool login(char[],char[]);
void customer(char[]);
void shop(char[]);
void sbycat(int);
void sbyrng(int,int);
void sbyavb(int);
bool add(int*, int, int);
bool remove(int*, int ,int);
int checkTotal(int*, int);
void checkout(char[],int*, int);
void updateHistory(char[], int*, int);
void addWishlist(int, char[]);
void viewWishlist(char[]);
void removeWishlist(char[], char[]);
bool cmparr(char* ,char*);
void viewHistory(char[]);
void giveFeedback(char[]);
void requestSupport(char[]);
double applyDiscount(double,int);
void viewDiscount();
void viewAnnouncment();
void viewfeedReply(char[]);
void viewreqReply(char[]);

//Function for customer

//function for employee
bool sbycode(int);
void employee();
void manageInventory(char[]);
void addStock(int,int,char[]);
void removeStock(int,int,char[]);
void editProduct(char[]);
void editName(char[], int);
void editPrice(int,int,char[]);
void removeProduct(int,char[]);
void addProduct(int, char[]);
void viewSupportreq(char[]);
void markResolved(int, char[]);
void stockAlert(char[]);
void feedbackResponse();
void response(int);
void deleteReq(int);
void deleteFeedback(int);

//Functions for employees

//Functions for Admins
void admin();
void manageAccount(char[], char[]);
void removeAccount(char[],char[]);
void changeUsername(char[]);
void changePassword(char[],char[]);
void Discounts();
void addDiscount();
void removeDiscount();
void viewActivityLog(char[]);
void viewAuditTrail();
bool isEnabled(char[]);
void disable2FA(char[]);
void enable2FA(char[]);
bool TwoFactorAuthentication(char[]);
int generateOTP();
void updateAnnouncment(char[]);

int main(){
    secureShop();
}
//General Functions

char encryptchar(char messageChar , char keywordChar){
    if(keywordChar>=97 && keywordChar<=122){
        if((int)messageChar>=97 && (int)messageChar<=122){//This encrypts the character if it is in lower case
            if(((int)messageChar-96) + ((int)keywordChar)-96>26){
                messageChar = 96 + ((int)messageChar+(int)keywordChar)-192-26;
            }
            else{
                messageChar = (((int)messageChar-96) + ((int)keywordChar)-96)+96;
            }
        }
        else if((int)messageChar>=65 && (int)messageChar<=90){//This encrypts the character if it is in upper case
            if(((int)messageChar-64) + ((int)keywordChar-96)>26){
                messageChar = 64 + ((int)messageChar+(int)keywordChar)-64-96-26;
            }
            else{
                messageChar = (((int)messageChar-64) + ((int)keywordChar)-96)+64;
            }
        }
    }
    return messageChar;
}

char decryptchar(char encryptedChar, char keyword){
     if(keyword>=97 && keyword<=122){
        if((int)encryptedChar>=97 && (int)encryptedChar<=122){//This decrypts the character if it is in lower case
            if(((int)encryptedChar - (int)keyword)<=0){
                int shift = ((int)keyword-96)-((int)encryptedChar-96);
                encryptedChar = 96+26-shift;
            }
            else{
                encryptedChar = (((int)encryptedChar-96) - ((int)keyword-96))+96;
            }
        }
        else if((int)encryptedChar>=65 && (int)encryptedChar<=90){//This decrypts the character if it is in upper case
            if((((int)encryptedChar-64) - ((int)keyword-96))<=0){
            int shift = ((int)keyword-96)-((int)encryptedChar-64);
            encryptedChar = 64+26-shift;
            }
            else{
                encryptedChar = (((int)encryptedChar-64) - ((int)keyword-96))+64;
            }
        }
     }
    return encryptedChar;
}

void decryptmessage(char message[], char keyword[]){
    int keySize = 0;
    for(int i=0 ; i<32 && keyword[i]!='\0'; i++){//Finding the actual size of the key
        keySize++;
    }

    for(int i=0 ; i<32 && message[i] != '\0'; i++){//Decrypting each character of message by passing it to decryptChar along with the respective key character
        message[i] = decryptchar(message[i], keyword[i%keySize]);
    }
    
    return ; 
}

void encryptmessage(char message[], char keyword[]){
    int keySize = 0;
    for(int i=0 ; i<32 && keyword[i]!='\0'; i++){//Finding the actual size of the key
        keySize++;
    }
    
    for(int i=0 ; i<32 && message[i] != '\0' ; i++){//Encrypting each character of message by passing it to encryptChar along with the respective key character 
        message[i] = encryptchar(message[i], keyword[i%keySize]);
    }
    
    return;
}
//General Functions

//Function for customer

void customerChoice(){
    int choice_cust;
    char user[64],file_path[] = "registered_users.txt";
    while(true){
        do{
            cout<<"What do you want to do?\n1: Register\n2: Login\n3: Go back\n-->";
            cin>>choice_cust;
            if(choice_cust>=1 && choice_cust<=3){
                break;
            }
            else{
                cout<<"Invalid type! Please try again\n\n";
            }
        }while(true);
        if(choice_cust==3){
            return;
        }
        else if(choice_cust==1){
            char file_path[] = "registered_users.txt";
            regster(file_path);
        }
        else if(choice_cust == 2){
            if(login(user,file_path)){
                cout<<"\nLogin Successful\n";
                customer(user);
            }
        }
    }
}
void secureShop(){
    int role;
    char user[64];
    while(true){
        cout<<"------------| Welcome to secure shop\n\n";
        do{
            cout<<"Please select Account type:\n";
            cout<<"1: Admin\n";
            cout<<"2: Emloyee\n";
            cout<<"3: Customer\n";
            cout<<"4: Exit\n->";
            cin>>role;
            if(role>=1 && role<=4){
                break;
            }
            else{
                cout<<"Invalid type! Please try again\n\n";
            }
        }while(true);
        switch(role){
            case 1:
                admin();
                break;
            case 2:
                employee();
                break;
            case 3:
                customerChoice();
                break;
            case 4:
                cout<<"Exited Program\n";
                return;
        }
    }
}
bool hasUpperCase(char pass[]){//This function returns true if the password contains uppercase letter 
    for(int i=0 ; i<64&&pass[i]!='\0'; i++){//This loop iterates through each character of the char array and checks if that character is uppercase
        if(pass[i]<=90 && pass[i] >= 65){
            return true;
        }
    }
    return false;
}
bool hasDigit(char pass[]){
    for(int i=0 ; i<64&&pass[i]!='\0' ; i++){//This function returns true if the password contains a digit
        if(pass[i]<=57 && pass[i] >= 48){//This loop iterates through each character of the char array and checks if it is a digit
            return true;
        }
    }
    return false;
}
void regster(char file_path[]){
    char uID[64],pass[64],check[64], isAdmin[]="registered_admins.txt";
    bool validate = 1;
    fstream reg_usr;
    
    cin.ignore();
    do{
        reg_usr.open(file_path, ios::in);
        cout<<"Type a username: ";
        cin>>uID;
        validate= 1;
        while(!reg_usr.eof()){
            reg_usr>> check;
            reg_usr.ignore(256,'\n');
            if (cmparr(uID,check)){
                cout<<"\nUsername is already taken\nTry a different username\n\n";
                validate=0;
                break;
            }
        }
        reg_usr.close();
        if(validate){
            break;
        }
    }while(true);
    reg_usr.close();
    reg_usr.open(file_path,ios::app);
    reg_usr<<endl<<uID<<"\t";
    cin.ignore();
    do{
        cout<<"Enter a password: ";
        cin>>pass;
        if(size(pass)>=8 && hasUpperCase(pass) && hasDigit(pass)){
            break;
        }
        else{
            cout<<"\n\nThe password is weak\nA strong password must have\n1 digit\n1 uppercase letter\nAtleast 8 characters\n\n";
        }
    }while(true);
    encryptmessage(pass, uID);
    reg_usr << pass;
    if(cmparr(file_path, isAdmin)){
        reg_usr<<" "<<0;
    }
    reg_usr.close();

    cout<<"\n\nSuccessfully registered \""<<uID<<"\"\n\n";
    return;
}
bool login(char user[],char file_path[]){
    char pass[64],check[64];
    bool validate = 1;
    fstream reg_user,activity;
    cin.ignore();
    do{
        reg_user.open(file_path, ios::in);
        cout<<"Enter your username: ";
        cin.getline(user,63,'\n');
        validate= 0;
        while(!reg_user.eof()){
            reg_user>>check;
            reg_user.ignore(256,'\n');
            if (cmparr(user,check)){
                validate=1;
                break;
            }
        }
        reg_user.close();
        if(validate){
            break;
        }
        else{
            cout<<"Username not found!\nPlease try again\n\n";
        }
    }while(true);
    reg_user.close();
    reg_user.open(file_path, ios::in);
    cout<<"\nWelcome "<<user<<"!\n";
    cout<<"\nPlease enter the password: ";
    cin.getline(pass,63,'\n');
    while(!reg_user.eof()){
        reg_user>>check;
        if(cmparr(user,check)){
            reg_user>>check;
            decryptmessage(check, user);
            for(int i=1 ; i<=5 ; i++){
                if(cmparr(check,pass)){
                    user = user;
                    reg_user.close();
                    return true;
                }
                else{
                    cout<<"Incorrect Password!\nPlease try again: ";
                    cin.getline(pass,63,'\n');
                }
            }
            activity.open("ActivityLog.txt",ios::app);
            activity<<endl<<user<<" [ Too many failed login attempts ]";
            activity.close();
            cout<<"Too many failed attempts\nPlease try again later\n";
            reg_user.close();
            return false;

        }
        reg_user.ignore(256,'\n');
    }
    return false;
}
void customer(char user[]){
    while(true){
        int choice;
        cout<<"\nWelcome "<<user<<endl<<endl;
        cout<<"What do you want to do?\n\n1: Shop for something\n2: View wishlist\n3: View Shopping history\n4: Provide feedback\n5: Request support\n6: View Discounts\n7: View announcment\n8: View Response\n9: Log out\n";
        do{
            cout<<"Enter your choice: ";
            cin>>choice;
            if(choice<=9 && choice>=1){
                break;
            }
            else{
                cout<<"Invalid selection!\nTry again\n";
            }
        }while(true);

        switch(choice){
            case 1:
                shop(user);
                break;
            case 2:
                viewWishlist(user);
                break;
            case 3: 
                viewHistory(user);
                break;
            case 4:
                giveFeedback(user);
                break;
            case 5:
                requestSupport(user);
                break;
            case 6:
                viewDiscount();
                cout<<"\nEnter any key to go back: ";
                cin>>choice;
                break;
            case 7:
                cout<<"\nAnnouncments: \n\n";
                viewAnnouncment();
                cout<<"\nEnter anything to go back: ";
                cin>>choice;
                break;
            case 8:
                do{
                    cout<<"\n1: View Feedback Response\n2: View Request response\n3: Go Back\n->";
                    cin>>choice;
                    if(choice>=1 && choice<=3){
                        break;
                    }
                    cout<<"Invalid Input!\n";
                }while(true);
                if(choice==1){
                    viewfeedReply(user);
                }
                else if(choice==2){
                    viewreqReply(user);
                }
                cout<<"\nEnter any key to go back: ";
                cin>>choice;
                break;
            case 9:
                cout<<"Logged out\n\n";
                return;
        }
    }
}
void shop(char user[]){
    fstream catalog,updated;
    int itemcode, price, stock, choice, i=0,code;
    double total;
    char name[64];
    bool cartex = 0,ask,back=0;
    int *cart;
    while(true){
        back =0;
        do{
            cout<<"\nSelect search method\n\n1: By category\n2: By price\n3: By Availability\n4: By code\n5: Go back\n->";
            cin>>choice;
            if(choice>=1 && choice<=5){
                break;
            }
            else{
                cout<<"Invalid input!\n";
            }
        }while(true);
        switch(choice){
            case 1:
                do{
                    cout<<"\nPlease select a category:\n";
                    cout<<"\n1: Groceries\n2: Electronics\n3: Bakery\n4: Cosmetics\n->";
                    cin>>choice;
                    if(choice>=1 && choice<=4){
                        break;
                    }
                    else{
                        cout<<"Invalid choice!\n";
                    }
                }while(true);
                sbycat(choice);
                break;
            case 2:
                int upper,lower;
                do{
                    cout<<"Enter a price range: ";
                    cin>>lower>>upper;
                    if(lower>0 && upper>lower){
                        break;
                    }
                    else{
                        cout<<"Invalid Range!\n";
                    }
                }while(true);
                sbyrng(lower,upper);
                break;
            case 3:
                int qty;
                cout<<"Enter the minimum quantity required: ";
                cin>>qty;
                sbyavb(qty);
                break;
            case 4:
                do{
                    cout<<"Enter the code of item: ";
                    cin>>code;
                    if(code>=0){
                        break;
                    }
                    cout<<"Invalid Code\nCode must not be negative\n";
                }while(true);
                sbycode(code);
                break;
            case 5:
                if(cartex){
                    do{
                        cout<<"If you go back your cart will be deleted\nDo you want to go back?\n1:Yes    0:NO\n->";
                        cin>>choice;
                        if(choice==0 || choice==1){
                            break;
                        }
                        else{
                            cout<<"Invalid Input\n";
                        }
                    }while(true);
                    if(choice){
                        delete []cart;
                        remove("catalog.txt");
                        rename("original.txt","catalog.txt");
                        return;
                    }
                }
                else{
                    return;
                }
        }

        while(true){
            do{
                cout<<"\n1: Add to cart\n2: Remove from cart\n3: Check Total\n4: Checkout\n5: Add to wishlist\n6: Go back\n-> ";
                cin>>choice;
                if(choice>=1 && choice<=6){
                    break;
                }
                else{
                    cout<<"\nInvalid choice!\n";
                }
            }while(true);
            switch(choice){
                case 1:
                    int cartsize;
                    if(!cartex){
                        char line[256];
                        updated.open("new.txt", ios::out|ios::app);
                        catalog.open("catalog.txt", ios::in);
                        while(!catalog.eof()){
                            catalog.getline(line,255,'\n');
                            updated<<endl<<line;
                        }
                        catalog.close();
                        updated.close();
                        rename("catalog.txt","original.txt");
                        rename("new.txt", "catalog.txt");
                        cout<<"\nEnter the size of the cart : ";
                        cin>>cartsize;
                        cart = new int[cartsize];
                        cartex=1;
                    }
                    if(i<cartsize){
                        cout<<"\nEnter the code of item to add: ";
                        cin>>code;
                        cout<<"\n";
                        if(add(cart, code, i)){
                            i++;
                        }        
                    }
                    else{
                        cout<<"\nCart is full\n";
                    }
                    break;
                case 2:
                    if(i==0){
                        cout<<"\nThe cart is empty\n";
                        break;
                    }
                    cout<<"\nEnter the code of the item to remove:";
                    cin>>code;
                    cout<<"\n";
                    if(remove(cart, code, i)){
                        i--;
                    }
                    break;
                case 3:
                    if(i==0){
                        cout<<"\nThe cart is empty\n";
                        break;
                    }
                    total = checkTotal(cart, i);
                    cout<<"\n Total : "<<total<<" pkr\n";
                    break;
                case 4:
                    if(i==0){
                        do{
                            cout<<"The cart is empty\nDo you still want to proceed to checkout?\n1: Yes\n0: No\n->";
                            cin>>ask;
                            if(ask==1 || ask ==0){
                                break;
                            }
                            else{
                                cout<<"Invalid input!\n";
                            }
                        }while(true);
                        if(!ask){
                            break;
                        } 
                    }
                    total = checkTotal(cart,i);
                    cout<<"\n Your total is :"<<total<<" pkr\n";
                    do{
                        cout<<"\nDo you want to apply any discount?\n1: Yes\n0: No\n->";
                        cin>>ask;
                        if(ask==1 || ask ==0){
                            break;
                        }
                        cout<<"Invalid input!\n";
                    }while(true);
                    if(ask==1){
                        total = total-((applyDiscount(total,i)/100)*total);
                        cout<<"\nThe total after discount is: "<<total<<endl;
                    }
                    do{
                        cout<<"\nDo you want to proceed with the checkout?\n1: Yes\n0: No\n->";
                        cin>>ask;
                        if(ask==1 || ask ==0){
                            break;
                        }
                        else{
                            cout<<"Invalid input!\n";
                        }
                    }while(true);
                    if(ask){
                        checkout(user,cart, i);
                        delete []cart;
                        return;
                    }
                    else{
                        break;
                    }
                case 5:
                    cout<<"\nEnter the code of item to add to wishlist: ";
                    cin>>code;
                    cout<<'\n';
                    addWishlist(code,user);
                    break;
                case 6:
                    back = 1;
            }
            if(back){
                break;
            }
        }
    }
}
void sbyrng(int lower, int upper){
    fstream catalog;
    int itemcode,price,stock;
    char name[64];

    catalog.open("catalog.txt", ios::in);
    cout<<endl<<setw(10)<<"Code |"<<setw(27)<<"Name |"<<setw(13)<<"Price |"<<setw(11)<<"Stock\n";
    cout<<"---------------------------------------------------------------\n";
    while(!catalog.eof()){
        catalog>>itemcode>>name>>price>>stock;
        if(price>=lower && price<=upper){
            cout<<setw(8)<<itemcode<<" |"<<setw(25)<<name<<" |"<<setw(8)<<price<<"pkr |"<<setw(8)<<"x"<<stock<<endl;
        }
    }
    catalog.close();
}
void sbycat(int choice){
    fstream catalog;
    int itemcode, price, stock;
    char name[64];
    cout<<setw(10)<<"Code |"<<setw(27)<<"Name |"<<setw(13)<<"Price |"<<setw(11)<<"Stock\n";
    cout<<"---------------------------------------------------------------\n";
    switch(choice){
        case 1:
            catalog.open("catalog.txt", ios::in);
            while(!catalog.eof()){
                catalog>>itemcode;
                if(itemcode<20000){
                    catalog>>name>>price>>stock;
                    cout<<setw(8)<<itemcode<<" |"<<setw(25)<<name<<" |"<<setw(8)<<price<<"pkr |"<<setw(8)<<"x"<<stock<<endl;                     
                }
                else{
                    catalog.ignore(256,'\n');
                }
            }
            break;
        case 2:
            catalog.open("catalog.txt", ios::in);
            while(!catalog.eof()){
                catalog>>itemcode;
                if(itemcode<30000 && itemcode>20000){
                    catalog>>name>>price>>stock;
                    cout<<setw(8)<<itemcode<<" |"<<setw(25)<<name<<" |"<<setw(8)<<price<<"pkr |"<<setw(8)<<"x"<<stock<<endl;                    
                }
                else{
                    catalog.ignore(256,'\n');
                }
            }
            break;
        case 3:
            catalog.open("catalog.txt", ios::in);
            while(!catalog.eof()){
                catalog>>itemcode;
                if(itemcode<40000 && itemcode>30000){
                    catalog>>name>>price>>stock;
                    cout<<setw(8)<<itemcode<<" |"<<setw(25)<<name<<" |"<<setw(8)<<price<<"pkr |"<<setw(8)<<"x"<<stock<<endl;                      
                }
                else{
                    catalog.ignore(256,'\n');
                }
            }
            break;
        case 4:
            catalog.open("catalog.txt", ios::in);
            while(!catalog.eof()){
                catalog>>itemcode;
                if(itemcode<50000 && itemcode>40000){
                    catalog>>name>>price>>stock;
                    cout<<setw(8)<<itemcode<<" |"<<setw(25)<<name<<" |"<<setw(8)<<price<<"pkr |"<<setw(8)<<"x"<<stock<<endl;                      
                }
                else{
                    catalog.ignore(256,'\n');
                }
            }
            break;
        default:
            catalog.open("catalog.txt", ios::in);
            while(!catalog.eof()){
                catalog>>itemcode;
                catalog>>name>>price>>stock;
                cout<<setw(8)<<itemcode<<" |"<<setw(25)<<name<<" |"<<setw(8)<<price<<"pkr |"<<setw(8)<<"x"<<stock<<endl;                  
            }
            break;
    }
    catalog.close();
}
void sbyavb(int qty){
    fstream catalog;
    int itemcode,price,stock;
    char name[64];

    catalog.open("catalog.txt", ios::in);
    cout<<endl<<setw(10)<<"Code |"<<setw(27)<<"Name |"<<setw(13)<<"Price |"<<setw(11)<<"Stock\n";
    cout<<"---------------------------------------------------------------\n";
    while(!catalog.eof()){
        catalog>>itemcode>>name>>price>>stock;
        if(stock>=qty){
            cout<<setw(8)<<itemcode<<" |"<<setw(25)<<name<<" |"<<setw(8)<<price<<"pkr |"<<setw(8)<<"x"<<stock<<endl;  
        }
    }
    catalog.close();
}
bool sbycode(int code){
    fstream catalog;
    int itemcode,price,stock;
    char name[64];
    catalog.open("catalog.txt", ios::in);
    while(!catalog.eof()){
        catalog>>itemcode;
        if(itemcode==code){
            catalog>>name>>price>>stock;
            cout<<endl<<setw(10)<<"Code |"<<setw(27)<<"Name |"<<setw(13)<<"Price |"<<setw(11)<<"Stock\n";
            cout<<"---------------------------------------------------------------\n";
            cout<<setw(8)<<itemcode<<" |"<<setw(25)<<name<<" |"<<setw(8)<<price<<"pkr |"<<setw(8)<<"x"<<stock<<endl;  
            catalog.close();
            return true;
        }
        catalog.ignore(256,'\n');
    }
    catalog.close();
    cout<<"\nItem not found\n";
    return false;
}
bool add(int* cart, int code, int i){
    int itemcode, stock, price;
    char name[64];
    bool found = 0;
    fstream catalog, temp;
    catalog.open("catalog.txt", ios::in);
    temp.open("temp.txt", ios::out | ios::app);
    while(!catalog.eof()){
        catalog>>itemcode>>name>>price>>stock;
        if(itemcode==code){
            if(stock>0){
                cout<<"Added "<<name<<" to cart\n"; 
                cart[i] = code;
                stock--;
                found  = 1;
            }
            else{
                cout<<"Sorry the item is out of stock\n";
                catalog.close();
                temp.close();
                remove("temp.txt");
                return false;
            }
        }
        temp<<endl<<itemcode<<" "<<name<<" "<<price<<" "<<stock;
    }
    catalog.close();
    temp.close();
    remove("catalog.txt");
    rename("temp.txt", "catalog.txt");
    if(found){
        return true;
    } 
    cout<<"Item not found\n";
    return false;
}
bool remove(int *cart, int code, int i){
    fstream catalog, temp;
    int item, price, stock;
    bool found=0;
    char name[64];
    for(int j=0; j<i ; j++){
        if(cart[j]==code){
            cart[j] = cart[i-1];
            cart[i-1] = 0;
            catalog.open("catalog.txt", ios::in);
            temp.open("updated.txt",ios::out|ios::app);
            while(!catalog.eof()){
                catalog>>item>>name>>price>>stock;
                if(item == code){
                    stock++;
                    cout<<"Removed "<<name<<" from the cart\n";
                    found=1;
                }
                temp<<endl<<item<<" "<<name<<" "<<price<<" "<<stock;
            }
            catalog.close();
            temp.close();
            remove("catalog.txt");
            rename("updated.txt", "catalog.txt");
            return true;
        }
    }
    cout<<"Item not found\n";
    return false;
}
int checkTotal(int *cart, int i){
    fstream catalog;
    int total = 0, code, price;
    char name[64];
    cout<<endl<<setw(10)<<"Code |"<<setw(27)<<"Name |"<<setw(13)<<"Price\n";
    cout<<"--------------------------------------------------\n";
    for(int j=0; j<i ; j++){
        catalog.open("catalog.txt", ios::in);
        while(!catalog.eof()){
            catalog>>code;
            if(code == cart[j]){
                catalog>>name>>price;
                total+= price;
                cout<<setw(8)<<code<<" |"<<setw(25)<<name<<" |"<<setw(8)<<price<<"pkr\n"; 
                catalog.close();
                break;
            }
            catalog.ignore(256,'\n');
        }
    }
    catalog.close();
    return total;
}
void checkout(char user[],int* cart,int i){
    remove("original.txt");
    fstream catalog, orders;
    int code;
    char name[64],line[256];
    bool found =0;
    orders.open("Orders.txt", ios::out | ios::app);
    orders<<endl<<user<<" [ ";
    for(int j=0 ; j<i ; j++){
        catalog.open("catalog.txt", ios::in);
        while(!catalog.eof()){
            catalog>>code;
            if(code==cart[j]){
                catalog>>name;
                orders<<name<<" ";
                break;
            }
            catalog.ignore(256,'\n');
        }
        catalog.close();
    }
    orders<<"]";
    orders.close();
    updateHistory(user, cart, i);
    
    cout<<"\n\nCheckout complete\nThanks for your purchase\n\n";
}
void updateHistory(char user[], int *cart ,int i){
    fstream history, temp, catalog;
    bool found = 0;
    int code;
    char name[64],line[256],term[] = "]";;
    history.open("history.txt", ios::in);
    temp.open("temphis.txt", ios::out | ios::app);
    while(!history.eof()){
        history>>name;
        if(name!=""){
            temp<<endl<<name<<" [";
            history.ignore(4,'\n');
            if(cmparr(name,user)){
                found=1;
                temp<<endl;
                for(int j=0 ; j<i ; j++){
                    catalog.open("catalog.txt",ios::in);
                    while(!catalog.eof()){
                        catalog>>code;
                        if(code==cart[j]){
                            catalog>>name;
                            temp<<"\t"<<name;
                            break;
                        }
                        catalog.ignore(256,'\n');
                    }
                    catalog.close();
                }
                cout<<"x";
                temp<<" ;";
            }
            do{
                history.getline(line,255,'\n');
                temp<<endl<<line;
            }while(!cmparr(line,term));
        }    
    }
    history.close();
    temp.close();
    if(!found){
        temp.open("temphis.txt", ios::app);
        temp<<endl<<user<<" [\n";
        for(int j=0 ; j<i ; j++){
                catalog.open("catalog.txt",ios::in);
                while(!catalog.eof()){
                    catalog>>code;
                    if(code==cart[j]){
                        catalog>>name;
                        temp<<"\t"<<name;
                        break;
                    }
                    catalog.ignore(256,'\n');
                }
                catalog.close();
            }
        temp<<"\n]";
        temp.close();
    }
    remove("history.txt");
    rename("temphis.txt", "history.txt");
}
void viewWishlist(char user[]){
    int choice,price,stock,icode;
    fstream wlist;
    char uname[64], code[16],itemcode[16],name[64],term[]="]";
    while(true){
        bool found =0;
        wlist.open("wishlist.txt", ios::in);
        while(!wlist.eof()){
            wlist>>uname;
            if(cmparr(uname,user)){
                cout<<"Your wishlist:\n\n";
                found = 1;
                wlist.ignore(4,'[');
                wlist>>code;
                cout<<endl<<setw(10)<<"Code |"<<setw(27)<<"Name |"<<setw(13)<<"Price |"<<setw(11)<<"Stock\n";
                cout<<"---------------------------------------------------------------\n";
                while(!cmparr(code,term)){
                    fstream catalog;
                    catalog.open("catalog.txt", ios::in);
                    while(!catalog.eof()){
                        catalog>>itemcode;
                        if(cmparr(itemcode,code)){
                            catalog>>name>>price>>stock;
                            cout<<setw(8)<<itemcode<<" |"<<setw(25)<<name<<" |"<<setw(8)<<price<<"pkr |"<<setw(8)<<"x"<<stock<<endl; 
                            break;
                        }
                        catalog.ignore(256,'\n');
                    }
                    catalog.close();
                    wlist>>code;
                }
            }
            wlist.ignore(1024,'\n');
        }
        wlist.close();
        if(!found){
            cout<<"\n\nYou don't have a wishlist\n\n ";
            return;
        }
        do{
            cout<<"\n1: Add to wishlist\n2: Remove from wishlist\n3: Go back\n->";
            cin>>choice;
            if(choice>=1 && choice<= 3){
                break;
            }
            cout<<"Inavlid Input";
        }while(true);
        switch (choice){
            case 1:
                cout<<"\nEnter the code of item to add to wishlist: ";
                cin>>icode;
                cout<<"\n";
                addWishlist(icode, user);
                break;
            case 2:
                cout<<"\nEnter the code of the item to remove: ";
                cin>>code;
                cout<<"\n";
                removeWishlist(code,user);
                break;
            case 3:
                return;
        }
    }
}
void addWishlist(int code, char user[]){
    fstream wlist, catalog, temp;
    int itemcode;
    char name[64],line[256],iname[64],term[]="";
    bool found=0;
    catalog.open("catalog.txt", ios::in);
    while(!catalog.eof()){
        catalog>>itemcode;
        if(itemcode==code){
            catalog>>iname;
            found=1;
            break;
        }
        catalog.ignore(256,'\n');
    }
    catalog.close();
    if(found){
        found =0;
        wlist.open("wishlist.txt", ios::in);
        temp.open("temp.txt",ios::out|ios::app);
        while(!wlist.eof()){
            wlist>>name;
            if(!cmparr(name,term)){
                temp<<endl<<name;
                if(cmparr(name,user)){
                    found=1;
                    wlist.ignore(4,'[');
                    wlist.getline(line,256,'\n');
                    temp<<" [ "<<code<<" "<<line;
                }
                else{
                    wlist.getline(line,256,'\n');
                    temp<<line;
                }
            }
        }
        wlist.close();
        temp.close();
        temp.open("temp.txt",ios::app);
        if(!found){
            temp<<endl<<user<<" [ "<<code<<" ]";
        }
        temp.close();
        wlist.close();
        remove("wishlist.txt");
        rename("temp.txt","wishlist.txt");
        cout<<"Added "<<iname<<" to wishlist\n";
        return;
    }
    else{
        cout<<"Item not found\n";
        return;
    }
}
void removeWishlist(char code[], char user[]){
    fstream wlist, temp;
    char name[64],icode[16],term[]="]",line[256];
    bool found=0;
    wlist.open("wishlist.txt",ios::in);
    temp.open("temp.txt",ios::app);
    while(!wlist.eof()){
        wlist>>name;
        temp<<endl<<name<<" [";
        wlist.ignore(4,'[');
        if(cmparr(user,name)){
            wlist>>icode;
            while(!cmparr(icode,term)){
                if(cmparr(code,icode)){
                    found=1;
                }
                else{
                    temp<<" "<<icode;
                }
                wlist>>icode;
            }
            temp<<" ]";
        }
        else{
            wlist.getline(line,255,'\n');
            temp<<line;
        }
    }
    wlist.close();
    temp.close();
    remove("wishlist.txt");
    rename("temp.txt","wishlist.txt");
    if(found){
        cout<<"Item removed from the wishlist\n";
        return;
    }
    else{
        cout<<"The item was not in the wishlist\n";
        return;
    }
}
bool cmparr(char *arr1, char *arr2){
    while(*arr1!='\0' && *arr2!='\0'){
        if(*arr1!=*arr2){
            return false;
        }
        arr1++;
        arr2++;
    }
    return *arr1=='\0' && *arr2=='\0';
}
void viewHistory(char user[]){
    fstream history;
    char name[64],item[64],term[]="]",term2[]= ";";
    int count = 1;
    bool found=0;
    history.open("history.txt",ios::in);
    while(!history.eof()){
        history>>name;
        if(cmparr(name,user)){
            cout<<"\nYour shopping History\n";
            cout<<setw(15)<<"\nOrder Number |"<<setw(8)<<"items...\n(latest first)\n";
            found=1;
            history.ignore(4,'\n');
            history>>item;
            do{
                cout<<count;
                do{
                    cout<<": "<<item;
                    history>>item;
                }while(!cmparr(item,term2));
                count++;
                cout<<endl;
                history>>item;
            }while(!cmparr(item,term));
        }
        history.ignore(1024,']');
        if(found){
            return;
        }
    }
    history.close();
    cout<<"\nYour Shopping history is empty\n";
}
void giveFeedback(char user[]){
    fstream feedback;
    char line[1024];
    int choice;
    cin.ignore();
    cout<<"\nPlease Give us feedback:\n->";
    cin.getline(line,1023,'\n');
    do{
        cout<<"\n1:Submit feedback\n0: Go Back\n->";
        cin>>choice;
        if(choice==1 || choice==0){
            break;
        }
        cout<<"Invalid input\n";
    }while(true);
    if(!choice){
        return;
    }
    feedback.open("feedback.txt",ios::app);
    feedback<<endl<<user<<" [ "<<line<<" ]";
    feedback.close();

    cout<<"\nThanks for your feedback\n";
    return;
}
void requestSupport(char user[]){
    fstream support;
    char line[1024];
    int choice;
    cin.ignore();
    cout<<"\nWrite your support Request here:\n->";
    cin.getline(line,1023,'\n');
    do{
        cout<<"\n1:Submit Request\n0: Go Back\n->";
        cin>>choice;
        if(choice==1 || choice==0){
            break;
        }
        cout<<"Invalid input\n";
    }while(true);
    if(!choice){
        return;
    }
    support.open("Support.txt",ios::app);
    support<<endl<<user<<" [ "<<line<<" ] pending ;";
    support.close();

    cout<<"\nYour Support request has been submitted\nOur team will respond to it shortly\n";
    return;
}
double applyDiscount(double total, int i){
    fstream discount;
    char code[64], promo[64],type;
    int min,disc;
    bool found=0;
    cout<<"Enter the promocode: ";
    cin>>promo;
    discount.open("discount.txt",ios::in);
    while(!discount.eof()){
        discount>>code;
        if(cmparr(code,promo)){
            found = 1;
            discount>>type>>min>>disc;
            break;
        }
        discount.ignore(1024,'\n');
    }
    discount.close();
    if(!found){
        cout<<"Discount code not found\n";
        return 0;
    }
    if(type=='A' && total>=min){
        return disc;
    }
    else if(type=='Q' && i>=min){
        return disc;
    }
    else{
        cout<<"\nDiscount is not applicable\n";
        return 0;
    }
}
void viewDiscount(){
    fstream discount;
    bool found=0;
    char code[64],line[1024];
    discount.open("discount.txt",ios::in);
    while(!discount.eof()){
        discount>>code;
        discount.ignore(64,'[');
        discount.getline(line,1023,']');
        cout<<"\nDiscount code: "<<code<<"\nDescription: "<<line<<endl;
        discount.ignore(4,'\n');
        found =1;
    }
    discount.close();
    if(!found){
        cout<<"No Discounts available for now :(\n";
        return;
    }
    return;
}
void viewAnnouncment(){
    fstream annc;
    char line[1024];
    int i=1;
    annc.open("Announcments.txt", ios::in);
    while(!annc.eof()){
        annc.getline(line,1023,'\n');
        cout<<i++<<": "<<line<<endl;
    }
    annc.close();
}
void viewfeedReply(char user[]){
    fstream file;
    char uname[64], req[1024], rep[1024],check[2],cmpare[] = "{";
    bool found=0;
    file.open("feedback.txt", ios::in);
    while(!file.eof()){
        file>>uname;
        if(cmparr(user, uname)){
            found = 1;
            file.ignore(4,'[');
            file.getline(req,1023,']');
            cout<<"\nYour Feedback: "<< req<<endl;
            file>>check;
            if(cmparr(check, cmpare)){
                file.getline(rep,1023,'}');
                cout<<"Response: "<<rep<<endl;
            }
            else{
                cout<<"No response\n";
            } 
        }
        else{
            file.ignore(1024,'\n');
        }
    }
    file.close();
    if(!found){
        cout<<"\nNo response yet\n";
    }
    return;
}
void viewreqReply(char user[]){
    fstream file;
    char uname[64], req[1024], rep[1024],check[2],status[16],cmpare[] = "{";
    bool found=0;
    file.open("Support.txt", ios::in);
    while(!file.eof()){
        file>>uname;
        if(cmparr(user, uname)){
            found = 1;
            file.ignore(4,'[');
            file.getline(req,1023,']');
            cout<<"\nYour Request: "<< req<<endl;
            file>>status;
            cout<<"Status: "<<status<<endl;
            file>>check;
            if(cmparr(check, cmpare)){
                file.getline(rep,1023,'}');
                file.ignore(4,'\n'); 
                cout<<"Response: "<<rep<<endl;
            }
            else{
                cout<<"No response\n";
            } 
        }
        else{
            file.ignore(1024,'\n');
        }
    }
    file.close();
    if(!found){
        cout<<"\nNo response yet\n";
    }
    return;
}
//Function for customer

//Functions for employee

void employee(){
    int choice;
    char user[64], file_path[]="registered_employees.txt";
    do{
        cout<<"\n\nEnter your choice:\n1: Login\n2: Go back\n->";
        cin>>choice;
        if(choice==1 || choice==2){
            break;
        }
        cout<<"Invalid choice\n";
    }while(true);
    if(choice==2){
        return;
    }
    if(!login(user,file_path)){
        return;
    }
    cout<<"\nLogin Succesful\n";
    while(true){
        do{
            cout<<"\n\nWelcome "<<user<<endl;
            cout<<"\nWhat do you want to do?\n1: Manage Inventory\n2: View Support requests\n3: View Stock alert\n4: Respond to feedback\n5: Make Announcment\n6: Log out\n->";
            cin>>choice;
            if(choice>=1 && choice<=6){
                break;
            }
            cout<<"Invalid Input\n";
        }while(true);

        switch(choice){
            case 1:
                manageInventory(user);
                break;
            case 2:
                viewSupportreq(user);
                break;
            case 3:
                stockAlert(user);
                break;
            case 4:
                feedbackResponse();
                break;
            case 5:
                char announce[1024];
                cin.ignore();
                cout<<"Write an Announcment: ";
                cin.getline(announce,1023,'\n');
                do{
                    cout<<"1: Make Announcment\n2: Go Back\n";
                    cin>>choice;
                    if(choice==1|| choice||2){
                        break;
                    }
                    cout<<"Invalid Input\n";
                }while(true);
                if(choice==1){
                    updateAnnouncment(announce);
                }
                break;
            case 6:
                cout<<"Logged out\n";
                return;
        }
    }
}
void manageInventory(char user[]){
    int choice,code,amount;
    while(true){
        do{
            cout<<"\nSelect any one option:\n1: View inventory\n2: Edit stock\n3: Edit product details\n4: Go back\n->";
            cin>>choice;
            if(choice>=1 && choice<=4){
                break;
            }
            cout<<"Invalid Input\n";
        }while(true);
        switch(choice){
            case 1:
                sbycat(0);
                break;
            case 2:
                do{
                    cout<<"\nSelect option:\n1: Add stock\n2: Remove stock\n3: Bo back\n->";
                    cin>>choice;
                    if(choice>=1 && choice<=3){
                        break;
                    }
                    cout<<"Invalid choice\n";
                }while(true);
                if(choice==3){
                    break;
                }
                cout<<"Enter the code of item : ";
                cin>>code;
                if(sbycode(code)){
                    if(choice==1){
                        do{
                            cout<<"Enter the amount of stock to add: ";
                            cin>>amount;
                            if(amount>0){
                                break;
                            }
                            cout<<"Invalid amount\n";
                        }while(true);
                        addStock(amount,code,user);                        
                        break;
                    }                  
                    else if(choice==2){
                        do{
                            cout<<"Enter the amount of stock to remove: ";
                            cin>>amount;
                            if(amount>0){
                                break;
                            }
                            cout<<"Invalid amount\n";
                        }while(true);
                        removeStock(amount,code,user);
                        break;
                    }                  
                }
                
                break;
            case 3:
                editProduct(user);
                break;
            case 4:
                return;
        }
    }
}
void addStock(int amount, int code, char user[]){
    fstream catalog,temp,report;
    int itemcode,price,stock;
    char name[64];
    catalog.open("catalog.txt",ios::in);
    temp.open("temp.txt", ios::app);
    while(!catalog.eof()){
        catalog>>itemcode>>name>>price>>stock;
        if(code==itemcode){
            stock+= amount;
            cout<<"\nAdded "<<amount<<" pieces of "<<name<<" to stock\n";
            report.open("SalesReport.txt",ios::app);
            report<<endl<<user<<" [ Added "<<amount<<" Pieces of itemcode: "<<code<<" to stock ]";
            report.close();
            report.open("AudtiTrail.txt",ios::app);
            report<<endl<<user<<" [ Added "<<amount<<" Pieces of itemcode: "<<code<<" to stock ]";
            report.close();
        }
        temp<<endl<<itemcode<<" "<<name<<" "<<price<<" "<<stock;
    }
    catalog.close();
    temp.close();
    remove("catalog.txt");
    rename("temp.txt", "catalog.txt");
    return;
}
void removeStock(int amount, int code, char user[]){
    fstream catalog,temp;
    int itemcode,price,stock;
    char name[64];
    catalog.open("catalog.txt",ios::in);
    temp.open("temp.txt", ios::app);
    while(!catalog.eof()){
        catalog>>itemcode>>name>>price>>stock;
        if(code==itemcode){
            stock-= amount;
            if(stock<0){
                amount+=stock;
                stock=0;
            }
            cout<<"\nRemoved "<<amount<<" pieces of "<<name<<" from stock\n";
            fstream report;
            report.open("SalesReport.txt",ios::app);
            report<<endl<<user<<" [ removed "<<amount<<" pieces of item code: "<<code<<" from stock ]";
            report.close();
            report.open("AuditTrail.txt",ios::app);
            report<<endl<<user<<" [ removed "<<amount<<" pieces of item code: "<<code<<" from stock ]";
            report.close();
        }
        temp<<endl<<itemcode<<" "<<name<<" "<<price<<" "<<stock;
    }
    catalog.close();
    temp.close();
    remove("catalog.txt");
    rename("temp.txt", "catalog.txt");
    return;
}
void editProduct(char user[]){
    fstream report;
    int code, choice,price;
    char name[64];
    while(true){
        do{
            cout<<"\nSelect option\n1: Edit Name\n2: Edit price\n3: Add product\n4: Remove product\n5: Go Back\n->";
            cin>>choice;
            if(choice>=1 && choice<=4){
                break;
            }
            cout<<"Invalid Input\n";
        }while(true);
        switch(choice){
            case 1:
                cout<<"Enter the item code: ";
                cin>>code;
                if(!sbycode(code)){
                    break;
                }
                cout<<"Enter the new name of product:";
                cin>>name;
                editName(name,code);
                return;
            case 2:
                cout<<"Enter the item code: ";
                cin>>code;
                if(!sbycode(code)){
                    break;
                }
                do{
                    cout<<"Enter the new price of product:";
                    cin>>price;
                    if(price>0){
                        break;
                    }
                    cout<<"Invalid price\n";
                }while(true);
                editPrice(price,code,user);
                return;
            case 3:
                do{
                    cout<<"Select Category:\n1: Groceries\n2: Electronics\n3: Bakery\n4: Cosmetics\n5: Go back\n->";
                    cin>>choice;
                    if(choice>=1 && choice<=5){
                        break;
                    }
                    cout<<"Invalid choice\n";
                }while(true);
                if(choice==5){
                    return;
                }
                else if(choice==1){
                    addProduct(10000,user);
                }
                else if(choice==2){
                    addProduct(20000,user);
                }
                else if(choice==3){
                    addProduct(30000,user);
                }
                else if(choice==4){
                    addProduct(40000,user);
                }
                return;
            case 4:
                cout<<"Enter the item code: ";
                cin>>code;
                if(!sbycode(code)){
                    break;
                }
                do{
                    cout<<"\nOnce a product is removed it cannot be added back again!\nDo you want to remove this product from the catalog?\n\n1: Yes\n0: No\n->";
                    cin>>choice;
                    if(choice==1 || choice==0){
                        break;
                    }
                    cout<<"Invalid input!\n";
                }while(true);
                if(choice==0){
                    return;
                }
                removeProduct(code,user);
                return;
            case 5:
                return;
        }
    }
}
void editName(char newname[], int code){
    fstream catalog,temp;
    int itemcode,price,stock;
    char name[64];
    catalog.open("catalog.txt",ios::in);
    temp.open("temp.txt", ios::app);
    while(!catalog.eof()){
        catalog>>itemcode>>name>>price>>stock;
        if(code==itemcode){
            temp<<endl<<itemcode<<" "<<newname<<" "<<price<<" "<<stock;
            cout<<"\nChanged the name of"<<name<<" to "<<newname<<endl;
        }
        else{
            temp<<endl<<itemcode<<" "<<name<<" "<<price<<" "<<stock;
        }
    }
    catalog.close();
    temp.close();
    remove("catalog.txt");
    rename("temp.txt", "catalog.txt");
    return;
}
void editPrice(int newprice, int code, char user[]){
    fstream catalog,temp,report;
    int itemcode,price,stock;
    char name[64];
    catalog.open("catalog.txt",ios::in);
    temp.open("temp.txt", ios::app);
    while(!catalog.eof()){
        catalog>>itemcode>>name>>price>>stock;
        if(code==itemcode){
            temp<<endl<<itemcode<<" "<<name<<" "<<newprice<<" "<<stock;
            cout<<"\nChanged the price of "<<name<<" from "<<price<<" pkr to "<<newprice<<" pkr"<<endl;
            report.open("SalesReport.txt",ios::app);
            report<<endl<<user<<" [ changed the price of itemcode: "<<code<<" from "<<price<<" to "<<newprice<<" ]";
            report.close();
            report.open("AuditTrail.txt",ios::app);
            report<<endl<<user<<" [ changed the price of itemcode: "<<code<<" from "<<price<<" to "<<newprice<<" ]";
            report.close();
        }
        else{
            temp<<endl<<itemcode<<" "<<name<<" "<<price<<" "<<stock;
        }
    }
    catalog.close();
    temp.close();
    remove("catalog.txt");
    rename("temp.txt", "catalog.txt");
    return;
}
void addProduct(int range, char user[]){
    fstream catalog,temp,report,audit;
    char name[64],newname[64];
    int price, stock, itemcode, count=1,newprice;
    cout<<"Enter the name of product: ";
    cin>>newname;
    do{
        cout<<"Enter the price of product: ";
        cin>>newprice;
        if(newprice>0){
            break;
        }
        cout<<"Invalid price\n";
    }while(true);

    catalog.open("catalog.txt",ios::in);
    temp.open("temp.txt",ios::app);
    while(!catalog.eof()){
        catalog>>itemcode>>name>>price>>stock;
        if(itemcode>=range&& itemcode<(range+10000)){
            count++;
        }
        temp<<endl<<itemcode<<" "<<name<<" "<<price<<" "<<stock;
    }
    catalog.close();
    temp<<endl<<range+count<<" "<<newname<<" "<<newprice<<" "<<0;
    temp.close();
    cout<<"\nAdded "<<newname<<" to catalog\n";
    report.open("SalesReport.txt",ios::app);
    report<<endl<<user<<" [ Added a product with itemcode: "<<range+count<<" to catalog ]";
    report.close();
    audit.open("AuditTrail.txt",ios::app);
    audit<<endl<<user<<" [ Added a product with itemcode: "<<range+count<<" to catalog ]";
    audit.close();
    remove("catalog.txt");
    rename("temp.txt", "catalog.txt");
    return;
}
void removeProduct(int code,char user[]){
    fstream catalog,temp,report;
    int itemcode,price,stock;
    char name[64];
    catalog.open("catalog.txt",ios::in);
    temp.open("temp.txt", ios::app);
    while(!catalog.eof()){
        catalog>>itemcode>>name>>price>>stock;
        if(code==itemcode){
            cout<<"\nRemoved "<<name<<" from the catalog\n";
            report.open("SalesReport.txt",ios::app);
            report<<endl<<user<<" [ Removed the product with itemcode: "<<code<<" from to catalog ]";
            report.close();
            report.open("AuditTrail.txt",ios::app);
            report<<endl<<user<<" [ Removed the product with itemcode: "<<code<<" from to catalog ]";
            report.close();
        }
        else{
            temp<<endl<<itemcode<<" "<<name<<" "<<price<<" "<<stock;
        }
    }
    catalog.close();
    temp.close();
    remove("catalog.txt");
    rename("temp.txt", "catalog.txt");
    return;
}
void viewSupportreq(char empl[]){
    fstream support;
    int choice,count=1;
    char user[64],line[64],status[64],term[]= "]";
    support.open("Support.txt",ios::in);
    support.ignore(1024,'\n');
    while(!support.eof()){
        support>>user;
        support.ignore(4,'[');
        cout<<"Customer name: "<<user<<"\nRequest: ";
        support>>line;
        while(!cmparr(line,term)){
            cout<<line<<" ";
            support>>line;
        }
        support>>status;
        cout<<"\nStatus: "<<status<<endl;
        support.ignore(1024,'\n');
        do{
            cout<<"\n1: Mark as Resolved\n2: Go to next request\n3: Delete Request\n4: Go back\n->";
            cin>>choice;
            if(choice>=1 && choice<=3){
                break;
            }
            cout<<"Invalid input";
        }while(true);
        if(choice==4){
            support.close();
            return;
        }
        else if(choice==1){
            support.close();
            markResolved(count,empl);
            return;
        }
        else if(choice==3){
            support.close();
            deleteReq(count);
            return;
        }
        count++;
    }
    support.close();
    cout<<"\nPhew! No more support requests\nEnter anything key to go back\n";
    cin>>line;
    return;
}
void markResolved(int count ,char empl[]){
    fstream support,temp,report;
    int choice, i=1;
    char response[1024], line[1024],user[64];
    do{
        cout<<"Do you want to add a response?\n1: Yes\n2: NO\n->";
        cin>>choice;
        if(choice==1 || choice==2){
            break;
        }
        cout<<"Invalid Input\n";
    }while(true);

    if(choice==1){
        cin.ignore();
        cout<<"Write your response: ";
        cin.getline(response,1023,'\n');
    }
    temp.open("temp.txt",ios::app);
    support.open("Support.txt",ios::in);
    while(!support.eof()){
        support>>user;
        if(i == count){
            support.getline(line,1023,']');
            temp<<endl<<user<<line<<"] Resolved { "<<response<<" } ;";
            support.ignore(16,'\n');
            report.open("SalesReport.txt",ios::app);
            report<<endl<<empl<<" [ Resolved a support request by user: "<<user<<" ]";
            report.close();
        }
        else{
            support.getline(line,1023,'\n');
            temp<<endl<<user<<line;
        }
        i++;
    }
    support.close();
    temp.close();
    remove("Support.txt");
    rename("temp.txt","Support.txt");
    return;
}
void deleteReq(int count){
    fstream support,temp;
    char line[1024],user[64];
    int i=1;
    temp.open("temp.txt",ios::app);
    support.open("Support.txt",ios::in);
    while(!support.eof()){
        support>>user;
        if(i == count){
            support.ignore(1024,'\n');
            cout<<"\nRemoved Request\n";
        }
        else{
            support.getline(line,1023,'\n');
            temp<<endl<<user<<line;
        }
        i++;
    }
    support.close();
    temp.close();
    remove("Support.txt");
    rename("temp.txt","Support.txt");
    return;
}
void stockAlert(char user[]){
    fstream catalog;
    int code,price, stock,choice;
    char name[64];
    while(true){
        bool low=0;
        catalog.open("catalog.txt",ios::in);
        while(!catalog.eof()){
            catalog>>code>>name>>price>>stock;
            if(stock==0){
                low=1;
                cout<<"\nOUT OF STOCK:\nProduct name: "<<name<<"\nItem code: "<<code<<"\n";
            }
            else if(stock<5){
                low=1;
                cout<<"\nLow on Stock:\nProduct name: "<<name<<"\nItem code: "<<code<<"\nStock: "<<stock<<"\n";
            }
        }
        catalog.close();
        if(!low){
            cout<<"\nAll good\nNo Restocking required at present\n";
            return;
        }
        else{
            do{
                cout<<"\n1: Restock\n2: Go back\n->";
                cin>>choice;
                if(choice==1 || choice==2){
                    break;
                }
                cout<<"Invalid Input\n";
            }while(true);
            if(choice==2){
                return;
            }
            cout<<"Enter the code of product: ";
            cin>>code;
            if(sbycode(code)){
                do{
                    cout<<"Enter the amount to restock: ";
                    cin>>stock;
                    if(stock>0){
                        break;
                    }
                    cout<<"Invalid input\n";
                }while(true);
                addStock(stock,code,user);
            }
        }
    }
}
void feedbackResponse(){
    fstream feedback;
    int choice,count=1;
    char user[64],line[64],status[64],term[]= "]";
    feedback.open("feedback.txt",ios::in);
    feedback.ignore(1024,'\n');
    while(!feedback.eof()){
        feedback>>user;
        feedback.ignore(4,'[');
        cout<<"Customer name: "<<user<<"\nFeedBack: ";
        feedback>>line;
        while(!cmparr(line,term)){
            cout<<line<<" ";
            feedback>>line;
        }
        feedback.ignore(1024,'\n');
        do{
            cout<<"\n\n1: Respond to feedback\n2: Go to next feedback\n3: Delete feedback\n4: Go Back\n->";
            cin>>choice;
            if(choice>=1 && choice<=3){
                break;
            }
            cout<<"Invalid input";
        }while(true);
        if(choice==4){
            feedback.close();
            return;
        }
        else if(choice==1){
            feedback.close();
            response(count);
            return;
        }
        else if(choice==3){
            feedback.close();
            deleteFeedback(count);
            return;
        }
        count++;
    }
    feedback.close();
    cout<<"\nNo feedback for now\nEnter anything to go back\n";
    cin>>line;
    return;
}
void response(int count){
    fstream feedback,temp;
    int choice, i=1;
    char response[1024], line[1024],user[64];
    cin.ignore();
    cout<<"Write your response: ";
    cin.getline(response,1023,'\n');
    temp.open("temp.txt",ios::app);
    feedback.open("feedback.txt",ios::in);
    while(!feedback.eof()){
        feedback>>user;
        if(i == count){
            feedback.getline(line,1023,']');
            temp<<endl<<user<<line<<"] { "<<response<<" }";
            feedback.ignore(16,'\n');
        }
        else{
            feedback.getline(line,1023,'\n');
            temp<<endl<<user<<line;
        }
        i++;
    }
    feedback.close();
    temp.close();
    remove("feedback.txt");
    rename("temp.txt","feedback.txt");
    return;
}
void deleteFeedback(int count){
    fstream feedback,temp;
    char line[1024],user[64];
    int i=1;
    temp.open("temp.txt",ios::app);
    feedback.open("feedback.txt",ios::in);
    while(!feedback.eof()){
        feedback>>user;
        if(i == count){
            feedback.ignore(1024,'\n');
            cout<<"\nRemoved Feedback\n";
        }
        else{
            feedback.getline(line,1023,'\n');
            temp<<endl<<user<<line;
        }
        i++;
    }
    feedback.close();
    temp.close();
    remove("feedback.txt");
    rename("temp.txt","feedback.txt");
    return;
}

//Funtions for Employee

//Functions for Admin

void admin(){
    int choice;
    cin.ignore();
    char user[64], file_path[]="registered_admins.txt";
    do{
        cout<<"\n\nEnter your choice:\n1: Login\n2: Go back\n->";
        cin>>choice;
        if(choice==1 || choice==2){
            break;
        }
        cout<<"Invalid choice\n";
    }while(true);
    if(choice==2){
        return;
    }
    if(!login(user,file_path)){
        return;
    }
    if(!TwoFactorAuthentication(user)){
        return;
    }
    cout<<"\nLogin Successful\n";
    while(true){
        do{
            cout<<"\n\nWelcome "<<user<<endl;
            cout<<"\nWhat do you want to do?\n1: Manage Accounts\n2: Manage Inventory\n3: Manage Discounts and promotions\n4: View Activity Log\n5: View Audit trail\n6: Two Factor Authentication\n7: Make Announcment\n8: Log out\n->";
            cin>>choice;
            if(choice>=1 && choice<=8){
                break;
            }
            cout<<"Invalid Input\n";
        }while(true);

        switch(choice){
            case 1:
                do{
                    cout<<"1: Admin Accounts\n2: Employee Accounts\n3: Customer Accounts\n4: Go back\n->";
                    cin>>choice;
                    if(choice>=1 && choice<=4){
                        break;
                    }
                    cout<<"Invalid Input!\n";
                }while(true);
                if(choice==4){
                    break;
                }
                else if(choice==1){
                    char file_path[] = "registered_admins.txt";
                    manageAccount(file_path,user);
                    break;
                }
                else if(choice==2){
                    char file_path[] = "registered_employees.txt";
                    manageAccount(file_path,user);
                    break;
                }
                else if(choice==3){
                    char file_path[] = "registered_users.txt";
                    manageAccount(file_path,user);
                    break;
                }
                break;
            case 2:
                manageInventory(user);
                break;
            case 3:
                Discounts();
                break;
            case 4:
                viewActivityLog(user);
                break;
            case 5:
                viewAuditTrail();
                break;
            case 6:
                if(isEnabled(user)){
                    do{
                        cout<<"1: Disable Two factor Authentication\n2: Go back\n->";
                        cin>>choice;
                        if(choice==1 || choice == 2){
                            break;
                        }
                        cout<<"Invalid Input\n";
                    }while(true);
                    if(choice==2){
                         break;
                    }
                    else{
                        disable2FA(user);
                        cout<<"\nDisabled Two factor authentication\n";
                        break;
                    }
                }
                else{
                    do{
                        cout<<"1: Enable Two factor Authentication\n2: Go back\n->";
                        cin>>choice;
                        if(choice==1 || choice == 2){
                            break;
                        }
                        cout<<"Invalid Input\n";
                    }while(true);
                    if(choice==2){
                         break;
                    }
                    else{
                        enable2FA(user);
                        cout<<"\nEnabled Two factor authentication\n";
                        break;
                    }
                }
                break;
            case 7:
                char announce[1024];
                cin.ignore();
                cout<<"Write an Announcment: ";
                cin.getline(announce,1023,'\n');
                do{
                    cout<<"1: Make Announcment\n2: Go Back\n";
                    cin>>choice;
                    if(choice==1|| choice||2){
                        break;
                    }
                    cout<<"Invalid Input\n";
                }while(true);
                if(choice==1){
                    updateAnnouncment(announce);
                }
                break;
            case 8:
                cout<<"Logged out\n";
                return;
        }
    }
}
void manageAccount(char filepath[],char user[]){
    fstream registered;
    int choice;
    while(true){
        do{
            cout<<"\n1: Add Account\n2: Remove account\n3: Edit account \n4: Go back\n->";
            cin>>choice;
            if(choice>=1 && choice<=4){
                break;
            }
            cout<<"Invalid Input\n";
        }while(true);
        
        switch(choice){
            case 1:
                regster(filepath);
                break;
            case 2:
                removeAccount(filepath,user);
                break;
            case 3:
                do{
                    cout<<"1: Change username\n2: Change Password\n3: Go back\n->";
                    cin>>choice;
                    if(choice>=1 && choice<=3){
                        break;
                    }
                    cout<<"Invalid Input";
                }while(true);
                if(choice==3){
                    break;
                }
                else if(choice==1){
                    changeUsername(filepath);
                    break;
                }
                else if(choice==2){
                    changePassword(filepath,user);
                    break;
                }
                break;
            case 4:
                return;
        }   
    }
}
void removeAccount(char filepath[], char admin[]){
    fstream registered,temp,audit;
    char user[64],pass[64],reg_user[64], isAdmin[] = "registered_admins.txt";
    bool found = 0, TFA;
    cout<<"Enter the username: ";
    cin>>user;
    registered.open(filepath,ios::in);
    temp.open("temp.txt",ios::app);
    while(!registered.eof()){
        registered>>reg_user>>pass;
        if(cmparr(filepath, isAdmin)){
            registered>>TFA;
        }
        if(cmparr(user,reg_user)){
            found=1;
            cout<<"\nRemoved user: "<<user<<endl;
            audit.open("AuditTrail.txt",ios::app);
            audit<<endl<<admin<<" [ Removed "<<user<<" ]";
            audit.close();
        }
        else{
            if(cmparr(filepath,isAdmin)){
                temp<<endl<<reg_user<<" "<<pass<<" "<<TFA;
            }
            else{
                temp<<endl<<reg_user<<" "<<pass;
            }
        }
    }
    registered.close();
    temp.close();
    remove(filepath);
    rename("temp.txt",filepath);
    if(!found){
        cout<<"\nUsername not found\n";
        return;
    }
}
void changeUsername(char filepath[]){
    fstream registered,temp;
    char user[64],pass[64],reg_user[64],newuser[64];
    bool found = 0;
    cout<<"Enter the username: ";
    cin>>user;
    cout<<"Enter the new username: ";
    cin>>newuser;
    registered.open(filepath,ios::in);
    temp.open("temp.txt",ios::app);
    while(!registered.eof()){
        registered>>reg_user>>pass;
        if(cmparr(user,reg_user)){
            found=1;
            temp<<endl<<newuser<<" "<<pass;
            cout<<"\nChanged the username from "<<user<<" to "<<newuser<<endl;
        }
        else{
            if(cmparr(newuser,reg_user)){
                cout<<"\nThe username is already in use\n";
                temp.close();
                registered.close();
                remove("temp.txt");
                return;
            }
            temp<<endl<<reg_user<<" "<<pass;
        }
    }
    registered.close();
    temp.close();
    remove(filepath);
    rename("temp.txt",filepath);
    if(!found){
        cout<<"\nUsername not found\n";
        return;
    }
}
void changePassword(char filepath[], char admin[]){
    fstream registered,temp,audit;
    char user[64],pass[64],reg_user[64],newpass[64];
    bool found = 0;
    cout<<"Enter the username: ";
    cin>>user;
    do{
        cout<<"Enter a password: ";
        cin>>newpass;
        if(size(newpass)>=8 && hasUpperCase(newpass) && hasDigit(newpass)){
            break;
        }
        else{
            cout<<"\n\nThe password is weak\nA strong password must have\n1 digit\n1 uppercase letter\nAtleast 8 characters\n\n";
        }
    }while(true);
    registered.open(filepath,ios::in);
    temp.open("temp.txt",ios::app);
    while(!registered.eof()){
        registered>>reg_user>>pass;
        if(cmparr(user,reg_user)){
            found=1;
            temp<<endl<<user<<" "<<newpass;
            cout<<"\nChanged the password of "<<user<<" successfully\n";
            audit.open("AuditTrail.txt",ios::app);
            audit<<endl<<admin<<" [ Changed the password of "<<user<<" to "<<newpass<<" ]";
            audit.close();
        }
        else{
            temp<<endl<<reg_user<<" "<<pass;
        }
    }
    registered.close();
    temp.close();
    remove(filepath);
    rename("temp.txt",filepath);
    if(!found){
        cout<<"\nUsername not found\n";
        return;
    }
}
void Discounts(){
    int choice;
    while(true){
        do{
            cout<<"1: Add discount\n2: Remove discount\n3: Go back\n->";
            cin>>choice;
            if(choice>=1 && choice<=3){
                break;
            }
            cout<<"Invalid Input\n";
        }while(true);
        switch(choice){
            case 1:
                addDiscount();
                break;
            case 2:
                removeDiscount();
                break;
            case 3:
                return;
        }
    }
}
void addDiscount(){
    fstream discount;
    int type,disc,min;
    char promo[64],line[1024];
    cout<<"Enter the Discount code: ";
    cin>>promo;
    do{
        cout<<"Select type:\n1: Quantity Based\n2: Amount Based\n->";
        cin>>type;
        if(type==1 || type==2){
            break;
        }
        cout<<"Invalid Input\n";
    }while(true);

    do{
        cout<<"Enter the % of discount: ";
        cin>>disc;
        if(disc>0 && disc<=100){
            break;
        }
        cout<<"Invalid Amount\n";
    }while(true);
    switch(type){
        case 1:
            do{
                cout<<"Enter the minimum quantity required: ";
                cin>>min;
                if(min>0){
                    break;
                }
                cout<<"Invalid Amount\n";
            }while(true);
            cin.ignore();
            cout<<"Write the decription: ";
            cin.getline(line,1023,'\n');
            discount.open("discount.txt",ios::app);
            discount<<endl<<promo<<" Q "<<min<<" "<<disc<<" [ "<<line<<" ]";
            discount.close();
            break;
        case 2:
            do{
                cout<<"Enter the minimum amount in pkr required: ";
                cin>>min;
                if(min>0){
                    break;
                }
                cout<<"Invalid Amount\n";
            }while(true);
            cin.ignore();
            cout<<"Write the decription: ";
            cin.getline(line,1023,'\n');
            discount.open("discount.txt",ios::app);
            discount<<endl<<promo<<" A "<<min<<" "<<disc<<" [ "<<line<<" ]";
            discount.close();
            break;
    }
    cout<<"\nAdded a new Discount: \""<<promo<<"\"\n";
    return;
}
void removeDiscount(){
    fstream discount,temp;
    bool found=0;
    char code[64], promo[64],line[1024];
    cout<<"Enter the discount code to remove: ";
    cin>>code;
    discount.open("discount.txt",ios::in);
    temp.open("temp.txt",ios::app);
    while(!discount.eof()){
        discount>>promo;
        discount.getline(line,1023,'\n');
        if(cmparr(code,promo)){
            found=1;
            cout<<"\nRemoved "<<code<<" from discounts\n";
        }
        else{
            temp<<endl<<promo<<line;
        }
    }
    discount.close();
    temp.close();
    remove("discount.txt");
    rename("temp.txt","discount.txt");
    if(!found){
        cout<<"Discount code not found\n";
    }
    return;
}
void viewActivityLog(char admin[]){
    fstream activity,audit;
    int choice;
    bool found =0;
    char user[64],line[1024];
    activity.open("ActivityLog.txt", ios::in);
    while(!activity.eof()){
        activity>>user;
        activity.ignore(4,'[');
        activity.getline(line,1023,']');
        cout<<endl<<user<<" : "<<line<<endl;
        activity.ignore(4,'\n');
        found =1;
    }
    activity.close();
    if(!found){
        cout<<"\nActivity Log is empty\n";
        return;
    }
    do{
        cout<<"\n1: Clear Activity Log\n2: Go Back\n->";
        cin>>choice;
        if(choice==1 || choice==2){
            break;
        }
        cout<<"Invalid Input\n";
    }while(true);
    if(choice==2){
        return;
    }
    do{
        cout<<"\nAre you sure you want to clear activity log?\n";
        cout<<"1: Yes\n2: No\n->";
        cin>>choice;
        if(choice==1 || choice==2){
            break;
        }
        cout<<"Invalid Input\n";
    }while(true);
    if(choice==2){
        return;
    }
    remove("ActivityLog.txt");
    activity.open("ActivityLog.txt",ios::app);
    activity<<"\t";
    activity.close();
    cout<<"\nCleared Activity logs\n";
    audit.open("AuditTrail.txt",ios::app);
    audit<<endl<<admin<<" [ Cleared activity log ]";
    audit.close();
    return;
}
void viewAuditTrail(){ 
    fstream activity;
    bool found =0;
    char user[64],line[1024];
    activity.open("AuditTrail.txt", ios::in);
    while(!activity.eof()){
        activity>>user;
        activity.ignore(4,'[');
        activity.getline(line,1023,']');
        cout<<endl<<user<<" : "<<line<<endl;
        activity.ignore(4,'\n');
        found =1;
    }
    activity.close();
    if(!found){
        cout<<"\nAudit Trail is empty\n";
        return;
    }
    cout<<"\nEnter anything to go back: ";
    cin>>found;
    return;
}
bool isEnabled(char user[]){
    fstream admins;
    char uname[64], pass[64];
    bool status;

    admins.open("registered_admins.txt",ios::in);
    while(!admins.eof()){
        admins>>uname>>pass>>status;
        if(cmparr(uname,user)){
            if(status){
                admins.close();
                return true;
            }
            else{
                admins.close();
                return false;
            }
        }
    }
    return false;
}
void disable2FA(char user[]){
    fstream admins,temp;
    char uname[64], pass[64];
    bool status;

    admins.open("registered_admins.txt", ios::in);
    temp.open("temp.txt", ios::app);

    while(!admins.eof()){
        admins>>uname>>pass>>status;
        if(cmparr(user,uname)){
            temp<<endl<<uname<<" "<<pass<<" "<<0;
        }
        else{
            temp<<endl<<uname<<" "<<pass<<" "<<status;
        }
    }
    admins.close();
    temp.close();
    remove("registered_admins.txt");
    rename("temp.txt", "registered_admins.txt");
    return;
}
void enable2FA(char user[]){
    fstream admins,temp;
    char uname[64], pass[64];
    bool status;

    admins.open("registered_admins.txt", ios::in);
    temp.open("temp.txt", ios::app);

    while(!admins.eof()){
        admins>>uname>>pass>>status;
        if(cmparr(user,uname)){
            temp<<endl<<uname<<" "<<pass<<" "<<1;
        }
        else{
            temp<<endl<<uname<<" "<<pass<<" "<<status;
        }
    }
    admins.close();
    temp.close();
    remove("registered_admins.txt");
    rename("temp.txt", "registered_admins.txt");
    return;
}
bool TwoFactorAuthentication(char user[]){
    fstream admins,otpfile,activity;
    char uname[64], pass[64];
    bool TFA;
    int OTP, input;
    admins.open("registered_admins.txt",ios::in);
    while(!admins.eof()){
        admins>>uname>>pass>>TFA;
        if(cmparr(user,uname)){
            if(TFA){
                OTP = generateOTP();
                otpfile.open("OTP.txt",ios::app);
                otpfile<<"Your OTP is: "<<OTP;
                otpfile.close();
                for(int i=1 ; i<=5 ; i++){
                    cout<<"Verify the OTP: ";
                    cin>>input;
                    if(input==OTP){
                        cout<<"\nOTP successfully verified!\n";
                        admins.close();
                        remove("OTP.txt");
                        return true;
                    }
                    else{
                        cout<<"\nIncorrect OTP!\nPlease try again\n";
                    }
                }
                cout<<"\nOTP verification Failed\nLogin Failed\n";
                admins.close();
                activity.open("ActivityLog.txt",ios::app);
                activity<<endl<<user<<" [ OTP verification FAILED ]";
                activity.close();
                remove("OTP.txt");
                return false;
            }
            else{
                return true;
            }
        }
    }
    admins.close();
    return false;
}
int generateOTP(){
    srand(time(NULL));
    int OTP = rand()%1000000;
    while(OTP<99999){
        OTP*=10;
        OTP += rand()%10;
    }
    return OTP;
}
void updateAnnouncment(char line[]){
    fstream annc, temp;
    int i=1;
    annc.open("Announcments.txt",ios::in);
    temp.open("temp.txt", ios::app);
    temp<<line;
    while(!annc.eof() && i<=7){
        annc.getline(line,1023,'\n');
        temp<<endl<<line;
        i++;
    }
    annc.close();
    temp.close();
    remove("Announcments.txt");
    rename("temp.txt", "Announcments.txt");

    return;
}