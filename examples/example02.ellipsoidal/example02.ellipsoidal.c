/*!   This is example02.ellipsoidal source file for
!       https://github.com/LiuGangKingston/C-CSV-TIKZ.git
!            Version 1.0
!   free for non-commercial use.
!   Please send us emails for any problems/suggestions/comments.
!   Please be advised that none of us accept any responsibility
!   for any consequences arising out of the usage of this
!   software, especially for damage.
!   For usage, please refer to the README file.
!   This code was written by
!        Gang Liu (gl.cell@outlook)
!                 (http://orcid.org/0000-0003-1575-9290)
!          and
!        Shiwei Huang (huang937@gmail.com)
!   Copyright (c) 2021
!
!   This file is formed by adding new lines at the
!   "Specific calculation to generate CSV files" area in the
!   functin "void MyComputing() {...}" at the end of the
!   template file.
! */


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <CCSVTikZ.h>


void Initialize(){
     CCSVTikZFileGroupInitialize();
}


void Finalize(){
     CCSVTikZFileGroupFinalize();
}


void MyComputing();


int main() {
    Initialize();
    MyComputing();
    Finalize();
    return 0;
}

void MyComputing() {

// Specific calculation to generate CSV files
// Specific calculation to generate CSV files

    int i, j, groupnumber, totallines, datalinesineachfile, startingline;
    double  a, b, startingangleofsoidal, endinggangleofsoidal, startinxofsoidal, startinyofsoidal, c, d, dk;
    double  startingangle, bigf, t, x, y, z, yprime, tangentangle, normalangle, incidentangle, reflectangle;
    FILE *  afile;

    groupnumber = 1;
    totallines = 10;
    startingline = 1;
    datalinesineachfile = 50;

    a=7.0e0;
    b=3.0e0;
    startingangleofsoidal = 35.0e0;
    endinggangleofsoidal = 325.0e0;
    startinxofsoidal = a * cos(startingangleofsoidal*Deg2Rad);
    startinyofsoidal = b * sin(startingangleofsoidal*Deg2Rad);
    c=-sqrt(a*a-b*b);

    afile = fopen("setup.scalars.csv", "w");
    if(afile == NULL){
       printf("In the function MyComputing()\n");
       printf("File open for setup.scalars.csv failed, then stopped. \n");
       Finalize();
       exit(0);
    }
    fprintf(afile, "a,b,c,startingangleofsoidal,endinggangleofsoidal,startinxofsoidal,startinyofsoidal\n");
    fprintf(afile, "%f, %f, %f, %f, %f, %f, %f \n",a,b,c,startingangleofsoidal,endinggangleofsoidal,startinxofsoidal,startinyofsoidal);
    fclose(afile);

    FileGroupSetupAndOpen(groupnumber,"iterated.alldata.",startingline,totallines,datalinesineachfile);
    FirstLineToAFileGroup(groupnumber,"c,d,startingangle,dk,bigf,t,x,y,yprime,"
                                      "tangentangle,normalangle,incidentangle,reflectangle,mycolor");

    d=fabs(c);
    for(j=1; j > -2; j=j-2) {
    for(i=startingline; i<=totallines; i++) {
       startingangle= j*(5.0e0 + 5.0e0*i*i);
       dk=d*cos(startingangle*Deg2Rad);
       bigf=a*a - dk*dk;
       t=b*b*(dk+sqrt(bigf+dk*dk))/bigf;
       x=t*cos(startingangle*Deg2Rad)-d;
       y=t*sin(startingangle*Deg2Rad);
       yprime=-b*b*x/(a*a*y);
       z = sqrt((b*b*x)*(b*b*x) + (a*a*y)*(a*a*y));
       if(x < 0.0e0) {
          if(y < 0.0e0) {
             tangentangle = asin(b*b*x /z) * Rad2Deg; }
          else {
             tangentangle = 180.0e0 + acos(a*a*y /z) * Rad2Deg; }
       }
       else {
          if(y  < 0.0e0) {
             tangentangle = acos(-a*a*y /z) * Rad2Deg;}
          else {
             tangentangle = acos(-a*a*y /z) * Rad2Deg;}
       }
       normalangle = tangentangle - 90.0e0;
       incidentangle = normalangle - startingangle;
       reflectangle = tangentangle + 90.0e0 + incidentangle;
       afile = PickAFileFromGroup(groupnumber, i);
       fprintf(afile, "%f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %s \n",
                              c,d,startingangle,dk,bigf,t,x,y,yprime,tangentangle,
                        normalangle,incidentangle,reflectangle,PickTypicalColor(i) );
    }
    }
    FileGroupClose(groupnumber);

}


