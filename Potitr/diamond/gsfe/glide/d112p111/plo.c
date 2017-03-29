#include<stdio.h>
#include<math.h>

#define pt 101
int main(){

double x[pt],area,E[pt];


FILE* fp;

fp=fopen("output","r");

int i;
for(i=0;i<pt;i++){

fscanf(fp,"%lf %lf  %lf",&x[i],&area,&E[i]);

}


double bain[pt];
for(i=0;i<pt;i++){

bain[i]=((E[i]-E[0])/area)*1000;

}
double a;

FILE* fp1;
fp1=fopen("latticefile.txt","r");
fscanf(fp1,"%lf ",&a);
for(i=0;i<pt;i++){

//fprintf(fp1,"%lf %.2lf\n",x[i],bain[i]);
printf("%lf %.2lf\n",x[i]/(a*sqrt(6.0)/2.0),bain[i]);


}
fclose(fp);
fclose(fp1);


return 0;

}
