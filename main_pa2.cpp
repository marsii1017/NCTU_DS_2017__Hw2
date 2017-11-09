#include <iostream>
#include <fstream>
#include<list>
#include <sstream>
#include <string>
#include <iomanip>
 #include <algorithm>
using namespace std;

int main(int argc, char** argv){
    ifstream inFile;
    ofstream myfile;
     inFile.open(argv[1]);//"case.txt"
     myfile.open (argv[2]);//"output.txt"
    int  start_number;
    int breaknumber;
    int i;

    struct Node{
        int name;
        string text;
    };
    list<Node>chain;
    ///////////////////////////////////////////////////////save start_number////////////////////////////////
    inFile >>start_number ;  //6
    cout<<start_number;
    cout<<"\n";
    //////////////////////////////////////build Node and fill into name and text(empty string)/////////////////////
    int tempx;
    i=0;
    int start_position;
    while ((inFile>> tempx )&&(tempx>0))
    {
        Node  tempnode;
        tempnode.name=tempx;
        tempnode.text= "";
        chain.push_back(tempnode);
        if(tempx==start_number){
            start_position=i;
        }
        i++;

    }
    cout<<"start_position="<<start_position<<'\n';
    ////////////////////////////////////// Print after build Node and fill into name and text(empty string)////////////////////////////////
    list<Node>::iterator it1;
    cout<<"List of Node.name=";
    for (list<Node>::iterator it=chain.begin() ; it != chain.end() ;++it){
            cout << (*it).name<<' ';

    }

    cout<<'\n'<<"size of Node:"<<chain.size()<<'\n';
  /*   it1=chain.begin();
     cout<<(*it1).name<<' ';
    advance(it1,chain.size()-1);
    //it1=chain.end();
     cout<<(*it1).name<<' ';
                                             //////////////// try begin(),end() //////////// */
///////////////////////////////////////// getline text string//////////////////////////////////////
    string temp;
     list<Node>::iterator it=chain.begin();
     advance(it,start_position);
     int clock_direction=0; // clockwirse=0 , anti-clockwise=1
     cout<<"begin:" <<(*it).name<<'\n';
 while(getline(inFile,temp)){
        if (temp.empty())
            continue;
        if (clock_direction==0){                                                       //clockwise
            if(breaknumber==1){
                break;
            }
            i=0;                                                                                      //i: record  position of temp
            for ( it ;  ( i<temp.size() )  ; i++){
                       if(it==chain.end())
                                it=chain.begin();

                        (*it).text=(*it).text+temp[i];
                        cout<< "clockwise_name:"<<(*it).name<<" text:"<<(*it).text<<'\n';

                    if(i==(temp.size()-1)){
                        cout<< "last_name:"<<(*it).name<<" text:"<<(*it).text<<'\n';
                        cout<<"temp_last:"<<temp[i]<<'\n';
                         myfile <<(*it).name<<" "<<(*it).text<<'\n';    //FILE OUT


                            if(temp[i]=='a' ||temp[i]== 'e' ||temp[i]== 'i' || temp[i]=='o' ||temp[i]== 'u'){
                                    clock_direction= clock_direction%2;//clockwise dose't change.
                                    cout<<"clock_diretion  doesn't change"<<'\n';
                                    cout<<"clock_direction:"<< clock_direction<<'\n';
                                     it=chain.erase(it);
                            }
                                else{
                                    clock_direction=(clock_direction+1)%2;
                                    cout<<"clock_diretion change"<<'\n';
                                    cout<<"clock_direction:"<< clock_direction<<'\n';
                                     it=chain.erase(it);
                                     if(it==chain.begin()){
                                        it=chain.end();
                                     }
                                     --it;
                                /*           if(it!=chain.begin()){
                                            --it;
                                        }
                                        if(it==chain.begin()){
                                           advance(it,(chain.size());
                                       // it=--chain.end();
                                            cout<<"SHOW ME :"<<(*it).name<<'\n';
                                        }*/

                                    }
                                //advance(it1,-1);
                            }
                            else
                                    ++it;
                                    if(chain.size()==1){
                                        it=chain.begin();
                                        cout<< "last_name:"<<(*it).name<<" text:"<<(*it).text<<'\n';
                                        myfile <<(*it).name<<" "<<(*it).text<<'\n';    //FILE OUT
                                    }

                    }   //// for ( it ;  ( i<temp.size() )  ; i++)

            }

        else{                                                                                   //anti-clockwise
                 cout<<"anti_clockwise"<<'\n';
                   i=0;
            for ( it ;  ( i<temp.size() )  ;  i++){
                  (*it).text=temp[i]+(*it).text;
                  cout<< "name:"<<(*it).name<<" text:"<<(*it).text<<'\n';
                    if(it==chain.begin() && i!=(temp.size()-1))
                        it=chain.end();
                if(i==(temp.size()-1)){
                           cout<< "last_name:"<<(*it).name<<" text:"<<(*it).text<<'\n';
                          cout<<"temp_last:"<<temp[i]<<'\n';
                          myfile <<(*it).name<<" "<<(*it).text<<'\n'; //FILE OUT
                            if(temp[i]=='a' ||temp[i]== 'e' ||temp[i]== 'i' || temp[i]=='o' ||temp[i]== 'u'){
                                    clock_direction= clock_direction%2;//clockwise dose't change.
                                    cout<<"clockwise doesn't change"<<'\n';
                                      it=chain.erase(it);
                                      if(it==chain.begin())
                                        it=chain.end();
                                       --it;
                            }
                            else{
                                clock_direction=(clock_direction+1)%2;
                                cout<<"clockwise changes"<<'\n';
                                  it=chain.erase(it);
                            }
                }
                else
                        --it;
                          if(chain.size()==1){
                                        it=chain.begin();
                                        cout<< "last_name:"<<(*it).name<<" text:"<<(*it).text<<'\n';
                                        myfile <<(*it).name<<" "<<(*it).text<<'\n';   // FILE OUT
                                    }
            }
        }
    }


 /*    //   cout<<temp;
       // cout<<" tempsize: "<<temp.size()<<'\n';
        i=0;
    for ( it ;  ( i<temp.size() )  ; ++it, i++){
            if(it==chain.end()){
                it=chain.begin();
            }
          (*it).text=(*it).text+temp[i];
          cout<< "name:"<<(*it).name<<" text:"<<(*it).text<<'\n';
         }




//    for (list<string>::iterator it=text_list.begin(); it != text_list.end(); ++it)
   //         cout << *it<<'\n'; */

        inFile.close();
        myfile.close();
        system("pause");
        return 0;

}

