#include "includes.h"
#include "structs.h"
#define TAM 3660725
void imprimeReview(review *x){
    cout<<endl<<"id:"<<x->id<<endl<<"review:"<<x->rev<<endl<<"voto:"<<x->votos<<endl<<"versao:"<<x->versao<<endl<<"data:"<<x->data<<endl;
}
string pegaAteVirgula(string linha,int *marcador){
    string aux="";
    int saida=0;
    int aspas=0;
    //cout<<linha.size()<<endl;
    while(saida==0 && *marcador!=linha.size()){
        //cout<<*marcador<<endl;
        if(linha[*marcador]=='"'){
            if(aspas==0){
                aspas=1;
            }
            else{
                aspas=0;
            }
        }
        if(linha[*marcador]==','){
            if(aspas==1){
                //cout<<"testedsafs:"<<linha[*marcador];
                aux=aux+linha[*marcador];
                *marcador=*marcador+1;
            }
            else{
                //cout<<"teste:"<<aux<<endl;
                *marcador=*marcador+1;
                return aux;
            }
        }
        else{
            //cout<<"tpadr:"<<linha[*marcador];
            aux=aux+linha[*marcador];
            *marcador=*marcador+1;
        }
        //cout<<*marcador;
    }
    //cout<<"teste:"<<aux<<endl;
    return aux;
}


void leArquivo(string caminho,review *dados){
    string linha,auxili;
    fstream arquivo(caminho);
    //string linha;
    int marcador=0;
    int i=0;
    if (!arquivo.is_open()){
        cout<<"erro arquivo nao aberto"<<endl;
        exit(1);
    }
    while (!arquivo.eof()){ //enquanto end of file for false continua
        marcador=0;
        getline(arquivo,linha);
        //dados[i].id=pegaAteVirgula(linha,&marcador);
        auxili=pegaAteVirgula(linha,&marcador);
        //cout<<"erro arquivo nao aberto//"<<auxili<<endl;
         dados[i].id=auxili;
         dados[i].rev=pegaAteVirgula(linha,&marcador);
         dados[i].votos=pegaAteVirgula(linha,&marcador);
         dados[i].versao=pegaAteVirgula(linha,&marcador);
         dados[i].data=pegaAteVirgula(linha,&marcador);
         //imprimeReview(&dados[i]);
         i++;
      }
    arquivo.close();
}