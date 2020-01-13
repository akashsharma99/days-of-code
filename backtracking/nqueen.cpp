#include <bits/stdc++.h>
using namespace std;
struct queen{
     int r,c;
}*queens;
int main(){
     int N;
     cin>>N;
     int **solution=(int**)calloc(N,sizeof(int*));
     for(int i=0;i<N;i++){
          solution[i]=(int*)calloc(N,sizeof(int));
     }
     queens=(struct queen*)calloc(N,sizeof(struct queen));
     for(int i=0;i<N;i++){
          queens[i].r=i;
          queens[i].c=-1;
     }
     int curRow=0;
     while(true){
          bool conflict=false;
          //cout<<"\ncurRow ==== "<<curRow<<'\n';
          do{
               (queens[curRow].c)++;
               conflict=false;
               //cout<<queens[curRow].c;
               if(queens[curRow].c==N){
                    conflict=true;
                    queens[curRow].c=-1;
                    //cout<<"\n go back \n";
                    break;
               }
               for(int q=0;q<curRow;q++){
                    int qc=queens[q].c;
                    int qr=queens[q].r;
                    int curCol=queens[curRow].c;

                    if(qc==curCol || (qc+qr)==(curCol+curRow) || abs(qc-curCol)==abs(qr-curRow) ){
                         conflict=true;
                         //cout<<"_conf_"<<qr<<qc<<", ";
                         break;
                    }
               }
          }while(conflict);
          if(conflict==true ){
               curRow--;
          }
          if(conflict==false){
               curRow++;
          }
          if(curRow==N){
               cout<<"SUCCESS"<<endl;
               for(int i=0;i<N;i++){
                    solution[queens[i].r][queens[i].c]=1;
               }
               for(int i=0;i<N;i++){
                    for(int j=0;j<N;j++){
                         cout<<solution[i][j]<<" ";
                    }
                    cout<<'\n';
               }
               break;
          }
          if(curRow==-1){
               cout<<"FAILED"<<endl;
               break;
          }
          
     }
     return 0;
}