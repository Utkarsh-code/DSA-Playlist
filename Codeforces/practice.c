#include<stdio.h>
int main(int argc, char const *argv[])
{
int ns,na,currState;
char inputString[1000];
printf("Enter the number of states : ");
scanf("%d",&ns);
printf("Enter the number of input alphabets : ");
scanf("%d",&na);
//takes present state, input and gives the next state
int trans[100][100];
//takes present state, input and gives the output
int output[100][100];
for(int i=0;i<ns;i++){
for(int j=0;j<na;j++){
printf("Enter next state for (curr state, input)(%d, %d): ", i, j);
scanf("%d", &trans[i][j]);
printf("Enter output for (curr state, input)(%d, %d): ", i, j);
scanf("%d", &output[i][j]);
}
}
printf("Enter initail state: ");
scanf("%d", &currState);
printf("Enter input string: ");
scanf("%s", inputString);
printf("Output of mealy machine: ");
int x=0;
while(inputString[x]!='\0'){
printf("%d",output[currState][inputString[x]-'0']);
currState = trans[currState][inputString[x]-'0'];
x++;
}
return 0;
}