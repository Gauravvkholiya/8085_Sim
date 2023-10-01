#include<bits/stdc++.h>
using namespace std;
class Interface
{
    bool Z=0,P=0,S=0,CY=0,AC=0;
    int B=0,C=0,D=0,E=0,H=0,L=0;             
    int A=95;
    unordered_map<int,int>m1;

public:
Interface()
{
}
void compute(string s)
{
    
    string temp="";
    if (s.find("MVI") != string::npos)
    {

    for (int i = s.size(); i >= 0; i--)
    {   
        if(s[i]!=' ')
            temp = temp+ s[i];
            else if( s[i]=' ')
            break;
    }
    reverse(temp.begin(),temp.end());
    
    if(s[4]=='A'){
        A = stoi(temp, 0, 16);
        cout << "The value at accumulator is :" << A << endl; // CHECKING THE VALUE OF ACCUMULATOR A
    }
    else{
        if(s[4]=='B'){
        B = stoi(temp, 0, 16);
        cout<<"The value at B is :"<< B <<endl;
        }
        if(s[4]=='C'){
        C = stoi(temp, 0, 16);
        cout<<"The value at C is :"<< C <<endl;
        }
        if(s[4]=='D'){
        D = stoi(temp, 0, 16);
        cout<<"The value at D is :"<< D <<endl;
        }
        if(s[4]=='E'){
        E = stoi(temp, 0, 16);
        cout<<"The value at E is :"<< E <<endl;
        }
        if(s[4]=='H'){
        H = stoi(temp, 0, 16);
        cout<<"The value at H is :"<< H <<endl;
        }
        if(s[4]=='L'){
        L = stoi(temp, 0, 16);
        cout<<"The value at L is :"<< L <<endl;
        }
    }
    }
    else if (s.find("mvi") != string::npos){
        cout<<"PLease enter the instruction in capital Letter"<<endl;
    }

    return;
}

void compute2(string s)
{
    string temp = "";
    if (s.find("MOV") != string::npos)
    {
        
        for (int i = 4; i <= s.size(); i++)
        {
            temp += s[i];
        }
        // cout << temp << endl;
        if (temp[0] == 'B' && temp[2] == 'A')
        {
            B = A;
            cout << "The value at register B :" << B << endl;
        }
        else if (temp[0] == 'A' && temp[2] == 'B'){
            A = B;
            cout << "The value at register A :" << A << endl;
        }
        if (temp[0] == 'A' && temp[2] == 'C')
        {
            A=C;
            cout << "The value at register A :" << A << endl;

        }
        else if (temp[0] == 'C' && temp[2] == 'A'){
            C=A;
            cout << "The value at register C :" << C << endl;
        }
        if (temp[0] == 'A' && temp[2] == 'D')
        {
            A=D;
            cout << "The value at register A :" << A << endl;
        }
        else if (temp[0] == 'D' && temp[2] == 'A'){
            D=A;
            cout << "The value at register D :" << D << endl;
        }
        if (temp[0] == 'E' && temp[2] == 'A')
        {
            E=A;
            cout << "The value at register E :" << E << endl;
        }
        else if (temp[0] == 'A' && temp[2] == 'E'){
            A=E;
            cout << "The value at register A :" << A << endl;
        }
        if (temp[0] == 'H' && temp[2] == 'A')
        {
            H=A;
            cout << "The value at register H :" << H << endl;
        }
        else if (temp[0] == 'A' && temp[2] == 'H'){
            A=H;
            cout << "The value at register A :" << A << endl;
        }
        if (temp[0] == 'L' && temp[2] == 'A')
        {
            L=A;
            cout << "The value at register L is :" << L << endl;
        }
        else if (temp[0] == 'A' && temp[2] == 'L'){
            A=L;
            cout << "The value at register A is :" << A << endl;
        }
            
    }
    else if (s.find("mov") != string::npos)
    {
        cout << "PLease enter the instruction in capital Letter" << endl;
    }
    return;
}
void compute3(string s)
{
    string temp = "";
    if (s.find("STA") != string::npos)
    {
        
        for(int i = 4;i<=s.size();i++)
        {
            temp += s[i];
        }
        int y = stoi(temp);
        if(y >=0 && y<= 65536 ){
        int x =  stoi(temp, 0, 16);
        m1[x] = A;
        cout<<"The value at memory address "<<x<<" is :"<<m1[x]<<endl;
        }
        else {
            cout<<"Enter a valid memory address"<<endl;
        }
    }
    else if (s.find("sta") != string::npos)
    {
        cout << "PLease enter the instruction in capital Letter" << endl;
    }
        
    return;
}
string add(string a, string b)                                 //ADDING THE BINARY STRING 
{
    string result = "";
    int temp = 0;
    int size_a = a.size() - 1;
    int size_b = b.size() - 1;
    while (size_a >= 0 || size_b >= 0 || temp == 1)
    {
        temp += ((size_a >= 0) ? a[size_a] - '0' : 0);
        temp += ((size_b >= 0) ? b[size_b] - '0' : 0);
        result = char(temp % 2 + '0') + result;
        temp /= 2;
        size_a--;
        size_b--;
    }
    return result;
}
string hexToBinary(string input)                                      //HEXADECIMAL TO BINARY      
{
    /*Using stoul() to get the decimal value
     * of the given String*/
    unsigned int x = stoul(input, nullptr, 16);

    /*Using bitset<16>(x).to_string() to get the binary
     * String of given integer*/
    string result = bitset<16>(x).to_string();

    /*Alternatively you may also merge above operations
          to one line like
          * string result = bitset<16>(stoul(input, nullptr, 16)).to_string();
            */
    return result;
}
string decToHexa(int n)                              //DECIMAL TO HEXADECIMAL
{
    // ans string to store hexadecimal number
    string ans = "";

    while (n != 0)
    {
        // remainder variable to store remainder
        int rem = 0;

        // ch variable to store each character
        char ch;
        // storing remainder in rem variable.
        rem = n % 16;

        // check if temp < 10
        if (rem < 10)
        {
            ch = rem + 48;
        }
        else
        {
            ch = rem + 55;
        }

        // updating the ans string with the character variable
        ans += ch;
        n = n / 16;
    }

    // reversing the ans string to get the final result
    int i = 0, j = ans.size() - 1;
    while (i <= j)
    {
        swap(ans[i], ans[j]);
        i++;
        j--;
    }
    return ans;
}
void compute4(string s)
{
    string temp = "";
    if (s.find("ADD") != string::npos)
    {
        
        for(int i = 4;i<=s.size();i++)
        {
            temp += s[i];
        }
        // cout<<temp[0]<<endl;
        if(temp[0]=='B')
        {
            
            string a = decToHexa(A);
            string b = decToHexa(B);
            string d = hexToBinary(a);
            string e = hexToBinary(b);

            cout << "Binary Representation of " << A << " is :" << d <<endl<< "Binary Representation of " << A << " is :" <<e << endl;
            string c = add(d,e);
            cout << "Sum of binary numbers :- " << c << endl;
            if(c[8]==1)
            {
                S = 1;
            }
            else {
                S=0;
            }
            if(stoi(c,0,2)==0)
            {
                Z=1;
            }
            else{
                Z=0;
            }
            int one =0;
            for(int i=8;i<c.size();i++)
            {
                if(c[i]=='1')
                {
                    one++;
                }
            }
            if(one%2==0)
            {
                P =1;
            }
            else{
                P =0;
            }
            if(c[7]==0)
            {
                CY = 0;
            }
            else{
                CY=1;
            }
            A = A + B;
        }
        else if(temp[0]=='C')
        {
            string a = decToHexa(A);
            string b = decToHexa(C);
            string d = hexToBinary(a);
            string e = hexToBinary(b);

            cout << d << "\t" << e << endl;
            string c = add(d, e);
            cout << c << endl;
            if (c[8] == 1)
            {
                S = 1;
            }
            else
            {
                S = 0;
            }
            if (stoi(c, 0, 2) == 0)
            {
                Z = 1;
            }
            else
            {
                Z = 0;
            }
            int one = 0;
            for (int i = 8; i < c.size(); i++)
            {
                if (c[i] == '1')
                {
                    one++;
                }
            }
            if (one % 2 == 0)
            {
                P = 1;
            }
            else
            {
                P = 0;
            }
            if (c[7] == 0)
            {
                CY = 0;
            }
            else
            {
                CY = 1;
            }
            A = A+C;
        }
        else if(temp[0]=='D')
        {
            string a = decToHexa(A);
            string b = decToHexa(D);
            string d = hexToBinary(a);
            string e = hexToBinary(b);

            cout << d << "\t" << e << endl;
            string c = add(d, e);
            cout << c << endl;
            if (c[8] == 1)
            {
                S = 1;
            }
            else
            {
                S = 0;
            }
            if (stoi(c, 0, 2) == 0)
            {
                Z = 1;
            }
            else
            {
                Z = 0;
            }
            int one = 0;
            for (int i = 8; i < c.size(); i++)
            {
                if (c[i] == '1')
                {
                    one++;
                }
            }
            if (one % 2 == 0)
            {
                P = 1;
            }
            else
            {
                P = 0;
            }
            if (c[7] == 0)
            {
                CY = 0;
            }
            else
            {
                CY = 1;
            }
            A = A+D;
        }
        else if(temp[0]=='E')
        {
            string a = decToHexa(A);
            string b = decToHexa(E);
            string d = hexToBinary(a);
            string e = hexToBinary(b);

            cout << d << "\t" << e << endl;
            string c = add(d, e);
            cout << c << endl;
            if (c[8] == 1)
            {
                S = 1;
            }
            else
            {
                S = 0;
            }
            if (stoi(c, 0, 2) == 0)
            {
                Z = 1;
            }
            else
            {
                Z = 0;
            }
            int one = 0;
            for (int i = 8; i < c.size(); i++)
            {
                if (c[i] == '1')
                {
                    one++;
                }
            }
            if (one % 2 == 0)
            {
                P = 1;
            }
            else
            {
                P = 0;
            }
            if (c[7] == 0)
            {
                CY = 0;
            }
            else
            {
                CY = 1;
            }
            A = A+E;
        }
        else if(temp[0]=='H')
        {
            string a = decToHexa(A);
            string b = decToHexa(H);
            string d = hexToBinary(a);
            string e = hexToBinary(b);

            cout << d << "\t" << e << endl;
            string c = add(d, e);
            cout << c << endl;
            if (c[8] == 1)
            {
                S = 1;
            }
            else
            {
                S = 0;
            }
            if (stoi(c, 0, 2) == 0)
            {
                Z = 1;
            }
            else
            {
                Z = 0;
            }
            int one = 0;
            for (int i = 8; i < c.size(); i++)
            {
                if (c[i] == '1')
                {
                    one++;
                }
            }
            if (one % 2 == 0)
            {
                P = 1;
            }
            else
            {
                P = 0;
            }
            if (c[7] == 0)
            {
                CY = 0;
            }
            else
            {
                CY = 1;
            }
            A = A+H;
        }
        else if(temp[0]=='L')
        {
            string a = decToHexa(A);
            string b = decToHexa(L);
            string d = hexToBinary(a);
            string e = hexToBinary(b);

            cout << d << "\t" << e << endl;
            string c = add(d, e);
            cout << c << endl;
            if (c[8] == 1)
            {
                S = 1;
            }
            else
            {
                S = 0;
            }
            if (stoi(c, 0, 2) == 0)
            {
                Z = 1;
            }
            else
            {
                Z = 0;
            }
            int one = 0;
            for (int i = 8; i < c.size(); i++)
            {
                if (c[i] == '1')
                {
                    one++;
                }
            }
            if (one % 2 == 0)
            {
                P = 1;
            }
            else
            {
                P = 0;
            }
            if (c[7] == 0)
            {
                CY = 0;
            }
            else
            {
                CY = 1;
            }
            A = A+L;
        }
        cout<<"The Value at Accumulator A is :"<<A<<endl;
        }
        else if (s.find("add") != string::npos)
        {
        cout << "PLease enter the instruction in capital Letter" << endl;
        }
    return;
}
void compute5(string s)
{
    string temp = "";
    if (s.find("SUB") != string::npos)
    {
        for(int i = 4;i<=s.size();i++)
        {
            temp += s[i];
        }
        cout<<temp[0]<<endl;
        if(temp[0]=='B')
        {
            A = A-B;
            
        }
        else if(temp[0]=='C')
        {
            A = A-C;
        }
        else if(temp[0]=='D')
        {
            A = A-D;
        }
        else if(temp[0]=='E')
        {
            A = A-E;
        }
        else if(temp[0]=='H')
        {
            A = A-H;
        }
        else if(temp[0]=='L')
        {
            A = A-L;
        }
        
        cout<<"The Value at Accumulator A is :"<<A<<endl;
        }
        else if (s.find("sub") != string::npos)
        {
        cout << "PLease enter the instruction in capital Letter" << endl;
        }
    return;
}
int HexToDec(string n) { return stoi(n, 0, 16); }
void compute6(string s)
{
    string temp = "";
    if (s.find("LDA") != string::npos)
    {
        for(int i = 4;i<s.size();i++)
        {
            temp+= s[i];
        }
        int x = stoi(temp, 0, 16);
        // cout<<x<<endl;
        cout<<"enter the value at "<<hex<<x<<endl;
        string y ="" ;
        cin>>y;
        int z = HexToDec(y);
        m1[x] = z;
        A = m1[x];
        cout<<"The value at accumulator is:"<<hex<<A<<endl; 
    }
    else if (s.find("lda") != string::npos)
    {
        cout << "PLease enter the instruction in capital Letter" << endl;
    }
    return;
}
int onesComplement(unsigned int n)
{
    int number_of_bits = floor(log2(n)) + 1;
    return ((1 << number_of_bits) - 1) ^ n;
}
void compute7(string s)
{
    if (s.find("CMA") != string::npos)
    {
        A = onesComplement(A);
        cout<<"one's complement of register A is done successfully "<<endl;
    }
    else if (s.find("cma") != string::npos)
    {
        cout << "PLease enter the instruction in capital Letter" << endl;
    }
    return;
}
void compute8(string s)
{
    if (s.find("ADI") != string::npos)
    {
        A +=1;
        cout<<"Added 1 to the one's complement to get 2's complement "<<endl;
    }
    else if (s.find("adi") != string::npos)
    {
        cout << "PLease enter the instruction in capital Letter" << endl;
    }
    return;
}
void print(string x)
{
    cout<< "The values of the registers are:"<<endl;
    cout<<"A : "<<hex << A <<endl;            //hex predefined funvtion for converting decimal to hexadecimal
    cout<<"B : "<< hex <<B <<endl;
    cout<<"C : "<< hex <<C <<endl;
    cout<<"D : "<< hex <<D <<endl;
    cout<<"E : "<< hex <<E <<endl;
    cout<<"H : "<< hex <<H <<endl;
    cout<<"L : "<< hex <<L <<endl;
    
    cout<<"The values of flags are :"<<endl;
    cout<<"Z:"<<Z<<endl;
    cout<<"P:"<<P<<endl;
    cout<<"S:"<<S<<endl;
    cout<<"CY:"<<CY<<endl;
    cout<<"AC:"<<AC<<endl;

    cout<<"--------------------------------------------------"<<endl;
    int y = stoi(x,0,16);
    cout << "The value at address " << y << " is : " << m1[y]<<endl;
}
};
int main()
{
cout << "\n\n\n\n                                    ----------------------------Welcome To Microprocessor Kit 8085--------------------------" << endl;
Interface I1;
string a;
while (a != "HLT")
{
    getline(cin, a);
    I1.compute(a);
    I1.compute2(a);
    I1.compute3(a);
    I1.compute4(a);
    I1.compute5(a);
    I1.compute6(a);
    I1.compute7(a);
    I1.compute8(a);
    
}
    int i =1;
    while(i){
        string x;
        cout<<"Enter the memory address you want to check :"<<endl;
        cin>>x;
        I1.print(x);
        cout<<"Do you want to check any another address(0/1)"<<endl;
        cin >> i;
    }
    cout<<"                             --------------------------------Program executed Successfully--------------------------------\n\n\n\n"<<endl;
    
    return 0;
}