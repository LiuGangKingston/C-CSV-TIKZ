#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    const double  PI             = 3.14159265358979323846e0;
    const double  Rad2Deg        = 57.29577951308232e0     ;  // 180/pi;
    const double  Deg2Rad        = 0.017453292519943296e0  ;  // pi/180;
    const double  NapierConstant = 2.71828182845904523536e0;
    const double  EulerNumber    = 2.71828182845904523536e0;

    const double  AccelerationDueToEarthGravity  = 9.80e0               ;// "m/s$^2$"
    const double  AtomicMassConstant             = 1.66053906660e-27    ;// kg
    const double  AvogadroNumber                 = 6.02214076e23        ;// "mol$^{-1}$"
    const double  BohrMagneton                   = 9.2740100783e-24     ;// "J/T"
    const double  BohrRadius                     = 5.29177210903e-11    ;// m
    const double  BoltzmannConstant              = 1.380649e-23         ;// "J/K"
    const double  ClassicalElectronRadius        = 2.8179403262e-15     ;// m
    const double  CoulombConstant                = 8.9875517923e9       ;// "N$\cdot $m$^2$/C$^2$"
    const double  ElementaryCharge               = 1.602176634e-19      ;// "C"
    const double  FaradayConstant                = 9.648533212e4        ;// C/mol
    const double  FineStructureConstant          = 7.2973525693e-3      ;//
    const double  FirstRadiationConstant         = 3.741771852e-16      ;// W$\dot m^2$
    const double  MassOfElectron                 = 9.1093837015e-31     ;// "kg"
    const double  MassOfNeutron                  = 1.67492749804e-27    ;// "kg"
    const double  MassOfProton                   = 1.67262192369e-27    ;// "kg"
    const double  NuclearMagneton                =  5.0507837461e-27    ;// "J/T"
    const double  PlanckConstant                 = 6.62607015e-34       ;// "J$\cdot $s"
    const double  RydbergConstant                = 1.0973731568160e7    ;// 1/m
    const double  SecondRadiationConstant        = 1.438776877e-2       ;// m$\dot K$
    const double  SpeedoFlightInVacuum           = 2.99792458e+8        ;// "m/s"
    const double  ThomsonCrossSection            = 6.6524587321e-29     ;//  $m^2$
    const double  UniversalGasConstant           = 8.314462618e0        ;// "J/(mol$\cdot $K)"
    const double  UniversalGravitationalConstant = 6.67430e-11          ;// "N$\cdot $m$^2$/kg$^2$"
    const double  VacuumElectricPermittivity     = 8.8541878128e-12     ;// "F/m"
    const double  VacuumMagneticPermeability     = 1.25663706212e-6     ;// "N/$A^2$"

    #define NumberOfTypicalColors  5
    #define LengthOfTypicalColors  16
    const char TypicalColors[NumberOfTypicalColors][LengthOfTypicalColors] = {
               "red\0            ","orange\0         ","yellow\0         ","green\0          ",
               "blue\0           " };

    #define NumberOfTikZColors  19
    #define LengthOfTikZColors  16
    const char TikZColors[NumberOfTikZColors][LengthOfTikZColors] = {
               "red\0            ","purple\0         ","magenta\0        ","pink\0           ",
               "violet\0         ","white\0          ","orange\0         ","yellow\0         ",
               "green\0          ","lime\0           ","brown\0          ","olive\0          ",
               "blue\0           ","cyan\0           ","teal\0           ","lightgray \0     ",
               "gray\0           ","darkgray\0       ","black\0          " };

    #define NumberOfColors  68
    #define LengthOfColors  16
    const char Colors[NumberOfColors][LengthOfColors] = {
               "Apricot\0        ","Aquamarine\0     ","Bittersweet\0    ","Black\0          ",
               "Blue\0           ","BlueGreen\0      ","BlueViolet\0     ","BrickRed\0       ",
               "Brown\0          ","BurntOrange\0    ","CadetBlue\0      ","CarnationPink\0  ",
               "Cerulean\0       ","CornflowerBlue\0 ","Cyan\0           ","Dandelion\0      ",
               "DarkOrchid\0     ","Emerald\0        ","ForestGreen\0    ","Fuchsia\0        ",
               "Goldenrod\0      ","Gray\0           ","Green\0          ","GreenYellow\0    ",
               "JungleGreen\0    ","Lavender\0       ","LimeGreen\0      ","Magenta\0        ",
               "Mahogany\0       ","Maroon\0         ","Melon\0          ","MidnightBlue\0   ",
               "Mulberry\0       ","NavyBlue\0       ","OliveGreen\0     ","Orange\0         ",
               "OrangeRed\0      ","Orchid\0         ","Peach\0          ","Periwinkle\0     ",
               "PineGreen\0      ","Plum\0           ","ProcessBlue\0    ","Purple\0         ",
               "RawSienna\0      ","Red\0            ","RedOrange\0      ","RedViolet\0      ",
               "Rhodamine\0      ","RoyalBlue\0      ","RoyalPurple\0    ","RubineRed\0      ",
               "Salmon\0         ","SeaGreen\0       ","Sepia\0          ","SkyBlue\0        ",
               "SpringGreen\0    ","Tan\0            ","TealBlue\0       ","Thistle\0        ",
               "Turquoise\0      ","Violet\0         ","VioletRed\0      ","White\0          ",
               "WildStrawberry\0 ","Yellow\0         ","YellowGreen\0    ","YellowOrange\0   " };


    const char* PickTypicalColor(int i) {return TypicalColors[abs(i)%NumberOfTypicalColors];}

    const char* PickTikZColor(int i)    {return TikZColors[abs(i)%NumberOfTikZColors];}

    const char* PickColor(int i)        {return Colors[abs(i)%NumberOfColors];}




  int TotalCCSVTikZFileNamePrefixes;
  struct CCSVTikZFileNamePrefixes {
         int ItsGroupNumber;
         char * NamePrefix;
         struct CCSVTikZFileNamePrefixes * NextPrefixes;
  };


  int TotalCCSVTikZFileGroupsSetup;
  const char CCSVTikZFileExtension[5]=".csv\0";

  struct CCSVTikZFileGroups {
         int TotalLinesInEachFile;
         int TotalFiles;
         int StartingLineNumber;
         int EndingLineNumber;
         int LineNumberDirection;
         int AbsoluteLineRange;
         FILE ** GroupFiles;
         struct CCSVTikZFileGroups * NextFileGroup;
  };


  struct CCSVTikZFileGroups *       HeadOfCCSVTikZFileGroups;
  struct CCSVTikZFileGroups *             CCSVTikZFileGroupTemp1;
  struct CCSVTikZFileGroups *             CCSVTikZFileGroupTemp2;
  struct CCSVTikZFileNamePrefixes * HeadOfCCSVTikZFileNamePrefixes;
  struct CCSVTikZFileNamePrefixes *       CCSVTikZFileNamePrefixTemp1;
  struct CCSVTikZFileNamePrefixes *       CCSVTikZFileNamePrefixTemp2;


void CCSVTikZFileGroupInitialize()
{    TotalCCSVTikZFileGroupsSetup = 0;
     TotalCCSVTikZFileNamePrefixes = 0;
     HeadOfCCSVTikZFileGroups = (struct CCSVTikZFileGroups*)
                   malloc(sizeof(struct CCSVTikZFileGroups));
     HeadOfCCSVTikZFileGroups->GroupFiles = NULL;
     HeadOfCCSVTikZFileGroups->NextFileGroup = NULL;
     HeadOfCCSVTikZFileNamePrefixes = (struct CCSVTikZFileNamePrefixes*)
                         malloc(sizeof(struct CCSVTikZFileNamePrefixes));
     HeadOfCCSVTikZFileNamePrefixes->NamePrefix = NULL;
     HeadOfCCSVTikZFileNamePrefixes->NextPrefixes = NULL;
}


void CCSVTikZFileGroupFinalize()
{    int i, j;
     FILE ** tempfiles;
     CCSVTikZFileGroupTemp1 = HeadOfCCSVTikZFileGroups;
     CCSVTikZFileGroupTemp2 = NULL;
     for(i=0; i<=TotalCCSVTikZFileGroupsSetup; i++) {
         if(CCSVTikZFileGroupTemp1->GroupFiles != NULL){
               tempfiles = CCSVTikZFileGroupTemp1->GroupFiles;
               for(j=0; j< CCSVTikZFileGroupTemp1->TotalFiles; j++){
                   if(tempfiles[j] != NULL) fclose(tempfiles[j]);
               }
               free(CCSVTikZFileGroupTemp1->GroupFiles);
               CCSVTikZFileGroupTemp1->GroupFiles = NULL;
         }
         CCSVTikZFileGroupTemp2 = CCSVTikZFileGroupTemp1->NextFileGroup;
         free(CCSVTikZFileGroupTemp1);
         CCSVTikZFileGroupTemp1 = CCSVTikZFileGroupTemp2;
     }
     TotalCCSVTikZFileGroupsSetup = 0;

     CCSVTikZFileNamePrefixTemp1= HeadOfCCSVTikZFileNamePrefixes;
     CCSVTikZFileNamePrefixTemp2 = NULL;
     for(i=0; i<=TotalCCSVTikZFileNamePrefixes; i++) {
         if(CCSVTikZFileNamePrefixTemp1->NamePrefix != NULL)
               free(CCSVTikZFileNamePrefixTemp1->NamePrefix);
         CCSVTikZFileNamePrefixTemp2 = CCSVTikZFileNamePrefixTemp1->NextPrefixes;
         free(CCSVTikZFileNamePrefixTemp1);
         CCSVTikZFileNamePrefixTemp1 = CCSVTikZFileNamePrefixTemp2;
     }
     TotalCCSVTikZFileNamePrefixes = 0;
}


void CCSVTikZFileGroupPointer(int GroupNumber){
     int i, j;
     CCSVTikZFileGroupTemp1 = HeadOfCCSVTikZFileGroups;
     CCSVTikZFileGroupTemp2 = HeadOfCCSVTikZFileGroups;
     for(i=0; i<GroupNumber; i++) {
         CCSVTikZFileGroupTemp2 = CCSVTikZFileGroupTemp1->NextFileGroup;
         CCSVTikZFileGroupTemp1 = CCSVTikZFileGroupTemp2;
     }
}

void Initialize();
void Finalize();




void FileGroupSetupAndOpen(int GroupNumber, char * FileNamePrefix,
                           int StartingLine, int EndingLine, int LinesInEachFile)
{    int i, j, k, prelen, existlen, tfiles;
     FILE ** tempfiles;
     char *  existname;
     char *  fullfilename;
     char    intaschar[20];

     if((GroupNumber < 1) || (GroupNumber > (TotalCCSVTikZFileGroupsSetup+1))) {
        printf("In the FileGroupSetupAndOpen(int GroupNumber, char * FileNamePrefix,");
        printf("               int StartingLine, int EndingLine, int LinesInEachFile)\n");
        printf("the value of GroupNumber can only be a positive integer: 1, 2, 3, ... in sequence.\n");
        printf("Here it can only be the (next) one, which is %d . \n", TotalCCSVTikZFileGroupsSetup+1);
        if(TotalCCSVTikZFileGroupsSetup > 0)
        printf("or one used earlier, which means less than %d . \n", TotalCCSVTikZFileGroupsSetup+1);
        printf("Since you are using %d , this code run stopped. \n", GroupNumber);
        Finalize();
        exit(0);
     }

     if(GroupNumber <= TotalCCSVTikZFileGroupsSetup) {
        CCSVTikZFileGroupPointer(GroupNumber);
        tempfiles = CCSVTikZFileGroupTemp1->GroupFiles;
        if(tempfiles != NULL){
           printf("In the FileGroupSetupAndOpen(int GroupNumber, char * FileNamePrefix,");
           printf("               int StartingLine, int EndingLine, int LinesInEachFile)\n");
           printf("Since the GroupNumber %d is being used now, you can not use it. \n", GroupNumber);
           printf("The next one is %d . \n", TotalCCSVTikZFileGroupsSetup+1);
           printf("For the above reason, this code run stopped.\n");
           Finalize();
           exit(0);
        }
     }

     i = 0;
     j = 0;
     while (FileNamePrefix[i] != '\0') {
        if((FileNamePrefix[i] != ' ') && ( FileNamePrefix[i] != '\t')) j = 1;
        i++;
     }
     if(j == 0) {
        printf("In the FileGroupSetupAndOpen(int GroupNumber, char * FileNamePrefix,");
        printf("               int StartingLine, int EndingLine, int LinesInEachFile)\n");
        printf("with the GroupNumber %d . \n", GroupNumber);
        printf("Since the FileNamePrefix is empty, this code run stopped.\n");
        Finalize();
        exit(0);
     }

     prelen = strlen(FileNamePrefix);
     CCSVTikZFileNamePrefixTemp1= HeadOfCCSVTikZFileNamePrefixes;
     CCSVTikZFileNamePrefixTemp2 = NULL;
     for(i=0; i < TotalCCSVTikZFileNamePrefixes; i++) {
         CCSVTikZFileNamePrefixTemp2 = CCSVTikZFileNamePrefixTemp1->NextPrefixes;
         existname = CCSVTikZFileNamePrefixTemp2->NamePrefix;
         existlen = strlen(existname);
         if(prelen == existlen) {
            k = 1;
            for(j=0; j < prelen; j++) {
                if(FileNamePrefix[j] != existname[j]) k = 0;
            }
            if(k == 1) {
               printf("In the FileGroupSetupAndOpen(int GroupNumber, char * FileNamePrefix,");
               printf("               int StartingLine, int EndingLine, int LinesInEachFile)\n");
               printf("with the GroupNumber %d . \n", GroupNumber);
               printf("The FileNamePrefix %s was used in previous group number: %d,\n", FileNamePrefix,
                                                           CCSVTikZFileNamePrefixTemp2->ItsGroupNumber);
               printf("when this function was called at %d time(s). \n", i+1);
               printf("Although just a WARNING, maybe you are trying to overwrite exsisting file(s).\n");
               printf("Although just a WARNING, maybe you are trying to overwrite exsisting file(s).\n");
               printf("Although just a WARNING, maybe you are trying to overwrite exsisting file(s).\n");
               //Finalize();
               //exit(0);
            }
         }
         CCSVTikZFileNamePrefixTemp1 = CCSVTikZFileNamePrefixTemp2;
     }

     CCSVTikZFileNamePrefixTemp2 = (struct CCSVTikZFileNamePrefixes*)
                      malloc(sizeof(struct CCSVTikZFileNamePrefixes));
     CCSVTikZFileNamePrefixTemp2->ItsGroupNumber = GroupNumber;
     existname = (char *) malloc((prelen+10)*sizeof(char));
     strcpy(existname,FileNamePrefix);
     CCSVTikZFileNamePrefixTemp2->NamePrefix = existname;
     CCSVTikZFileNamePrefixTemp2->NextPrefixes = NULL;
     CCSVTikZFileNamePrefixTemp1->NextPrefixes = CCSVTikZFileNamePrefixTemp2;
     TotalCCSVTikZFileNamePrefixes++;

     if(LinesInEachFile < 0) {
        printf("In the FileGroupSetupAndOpen(int GroupNumber, char * FileNamePrefix,");
        printf("               int StartingLine, int EndingLine, int LinesInEachFile)\n");
        printf("with the GroupNumber %d , \n", GroupNumber);
        printf("the value of LinesInEachFile is %d . \n", LinesInEachFile);
        printf("Not reasonable. Then stopped.\n");
        Finalize();
        exit(0);
     }

     tfiles = abs(StartingLine - EndingLine) / LinesInEachFile + 1;

     if(GroupNumber <= TotalCCSVTikZFileGroupsSetup) {
        CCSVTikZFileGroupPointer(GroupNumber);
     }
     else {
        CCSVTikZFileGroupPointer(TotalCCSVTikZFileGroupsSetup);
        TotalCCSVTikZFileGroupsSetup = GroupNumber;
        CCSVTikZFileGroupTemp1 = (struct CCSVTikZFileGroups*)
                    malloc(sizeof(struct CCSVTikZFileGroups));
        CCSVTikZFileGroupTemp1->NextFileGroup = NULL;
        CCSVTikZFileGroupTemp2->NextFileGroup = CCSVTikZFileGroupTemp1;
     }
     tempfiles = (FILE **) malloc(tfiles * sizeof(FILE *));
     CCSVTikZFileGroupTemp1->GroupFiles = tempfiles;
     CCSVTikZFileGroupTemp1->TotalLinesInEachFile = LinesInEachFile;
     CCSVTikZFileGroupTemp1->TotalFiles = tfiles;
     CCSVTikZFileGroupTemp1->StartingLineNumber = StartingLine;
     CCSVTikZFileGroupTemp1->EndingLineNumber = EndingLine;
     CCSVTikZFileGroupTemp1->AbsoluteLineRange = abs(EndingLine-StartingLine);
     CCSVTikZFileGroupTemp1->LineNumberDirection = 1;
     if((EndingLine-StartingLine) < 0)
     CCSVTikZFileGroupTemp1->LineNumberDirection = -1;

     fullfilename = (char *) malloc((prelen+strlen(CCSVTikZFileExtension)+40)*sizeof(char));
     for(i=0; i < tfiles; i++) {
         itoa((i+1), intaschar, 10);
         strcpy(fullfilename, FileNamePrefix);
         strcat(fullfilename, intaschar);
         strcat(fullfilename, CCSVTikZFileExtension);
         tempfiles[i] = fopen(fullfilename,"w");
         printf("File %s is opened as number %d in GroupNumber %d . \n", fullfilename, i+1, GroupNumber);
         //fprintf(tempfiles[i], "%s . \n \n", fullfilename);
     }
     free(fullfilename);


}


void FirstLineToAFileGroup(int GroupNumber, char * FirstLineWords){
     int j;
     FILE ** tempfiles;
     if((GroupNumber < 1) || (GroupNumber > (TotalCCSVTikZFileGroupsSetup))) {
        printf("In the FIrstLineToAFileGroup(int GroupNumber, char * FirstLineWords)\n");
        printf("the value of GroupNumber: %d is not available. This code run stopped.\n", GroupNumber);
        Finalize();
        exit(0);
     }
     CCSVTikZFileGroupPointer(GroupNumber);
     if(CCSVTikZFileGroupTemp1->GroupFiles == NULL){
        printf("In the FIrstLineToAFileGroup(int GroupNumber, char * FirstLineWords)\n");
        printf("the GroupNumber: %d is not active now. This code run stopped.\n", GroupNumber);
        Finalize();
        exit(0);
     }
     tempfiles = CCSVTikZFileGroupTemp1->GroupFiles;
     for(j=0; j< CCSVTikZFileGroupTemp1->TotalFiles; j++){
         fprintf(tempfiles[j], "%s\n", FirstLineWords);
     }
}


FILE * PickAFileFromGroup(int GroupNumber, int LineNumber){
     int i,j,k;
     FILE ** tempfiles;
     if((GroupNumber < 1) || (GroupNumber > (TotalCCSVTikZFileGroupsSetup))) {
        printf("In the PickAFileFromGroup(int GroupNumber, int LineNumber)\n");
        printf("the value of GroupNumber: %d is not available. This code run stopped.\n", GroupNumber);
        Finalize();
        exit(0);
     }
     CCSVTikZFileGroupPointer(GroupNumber);
     if(CCSVTikZFileGroupTemp1->GroupFiles == NULL){
        printf("In the PickAFileFromGroup(int GroupNumber, int LineNumber)\n");
        printf("the GroupNumber: %d is not active now. This code run stopped.\n", GroupNumber);
        Finalize();
        exit(0);
     }

     i = LineNumber - CCSVTikZFileGroupTemp1->StartingLineNumber;
     k = abs(i);
     if(  ((i*CCSVTikZFileGroupTemp1->LineNumberDirection) < 0)
        ||(k>CCSVTikZFileGroupTemp1->AbsoluteLineRange)         )  {
        printf("In the PickAFileFromGroup(int GroupNumber, int LineNumber)\n");
        printf("with the GroupNumber: %d  \n", GroupNumber);
        printf("the LineNumber: %d is not in the range \n", LineNumber);
        printf("from %d ",   CCSVTikZFileGroupTemp1->StartingLineNumber);
        printf("to %d . \n", CCSVTikZFileGroupTemp1->EndingLineNumber);
        printf("Then stopped. \n");
        Finalize();
        exit(0);
     }

     j = k / (CCSVTikZFileGroupTemp1->TotalLinesInEachFile);
     tempfiles =  CCSVTikZFileGroupTemp1->GroupFiles;
     return tempfiles[j];

}



void FileGroupClose(int GroupNumber){
     int j;
     FILE ** tempfiles;
     if((GroupNumber < 1) || (GroupNumber > (TotalCCSVTikZFileGroupsSetup))) {
        printf("In the FileGroupClose(int GroupNumber)\n");
        printf("the value of GroupNumber: %d is not available. This code run stopped..\n", GroupNumber);
        Finalize();
        exit(0);
     }
     CCSVTikZFileGroupPointer(GroupNumber);
     if(CCSVTikZFileGroupTemp1->GroupFiles != NULL){
        tempfiles = CCSVTikZFileGroupTemp1->GroupFiles;
        for(j=0; j< CCSVTikZFileGroupTemp1->TotalFiles; j++){
            if(tempfiles[j] != NULL) fclose(tempfiles[j]);
        }
        free(CCSVTikZFileGroupTemp1->GroupFiles);
        CCSVTikZFileGroupTemp1->GroupFiles = NULL;
     }

}





void Initialize(){
     CCSVTikZFileGroupInitialize();
}


void Finalize(){
     CCSVTikZFileGroupFinalize();
}



int main() {
    double x, y, z;
    char sentence[1000];
char ch, a, b;
char name[2][8] = {"gouri", "ram"};
FILE **flarray;
FILE  *rfl, *wfl, *gggfff;

Initialize();

int group = 1;
int sline = 0;
int tline = 33;
int linefile = 2;
char fnpx[20] = "gfsee\0";
FileGroupSetupAndOpen(group, fnpx, sline, tline, linefile);
char fnpx2[20] = "fghrttgf\0";
FileGroupSetupAndOpen(group+1, fnpx2, sline, tline, linefile);
FileGroupSetupAndOpen(group+2, fnpx2, sline, tline, linefile);
FileGroupSetupAndOpen(group+3, fnpx, sline, tline, linefile);
FileGroupSetupAndOpen(group+4, fnpx2, sline, tline, linefile);

FirstLineToAFileGroup(group+4, strcat(fnpx2,fnpx));

int i;
for(i=sline; i<=tline; i++) {
gggfff=PickAFileFromGroup(group+4, i);
fprintf(gggfff, "dddd %d dddd \n", i);
}


rfl=fopen("a.t","r");
wfl=fopen("b.t","w");



flarray = (FILE **) malloc(2 * sizeof(FILE *));
flarray[0] = rfl;
flarray[1] = wfl;
    // creating file pointer to work with files
    FILE *fptr;

    // opening file in writing mode
    fptr = fopen("program.txt", "w");

    // exiting program
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }
    printf("Enter a sentence:\n");
    fgets(sentence, sizeof(sentence), stdin);
    fprintf(fptr, "%s", sentence);
    fclose(fptr);


     char prompt[] = "Press Enter to explode:";
    fprintf(wfl, "%s", sentence);
    fprintf(wfl, "%s", prompt);

     char cp1[] = "gggddd234";
     fprintf(wfl, "%s%s", cp1,"\n");
     fprintf(wfl, "%s\n", name);
     fprintf(wfl, "%s\n", name[1]);
     fprintf(wfl, "%s%s", name,"\n");


      char * pthreecolors;
      pthreecolors = (char *) malloc(100*sizeof(char));
      for(i=0;i<2*NumberOfTikZColors;i++){
            strcpy(pthreecolors, PickTypicalColor(i));
      strcat(pthreecolors, PickTikZColor(i));
      strcat(pthreecolors, PickColor(i));
          fprintf(wfl, ",,%s%s,,,", pthreecolors,"\n");
      }

      fprintf(wfl, "fridays ");
      fprintf(wfl, "fridays ");
      fprintf(wfl, "fridays 333\n");
      fprintf(wfl, "fridays 4444\n");
      fprintf(wfl, "fridays 55555\n");
      fprintf(flarray[1], "fridays 55555\n");
      fprintf(flarray[1], "thursday \n");
      fprintf(flarray[1], "wulingweiyitengxilang \n");
      y=0.5e0;
      x=asin(y);
      z=x*180/PI;


      fprintf(flarray[1], "wulingweiyitengxilang %f \n",x);
      fprintf(flarray[1], "wulingweiyitengxilang %f \n",z);
      y=sin(30.0e0*PI/180);
      fprintf(flarray[1], "wulingweiyitengxilang %f \n",y*4);
      fprintf(flarray[1], "wulingweiyitengxilang %30.26lf \n",Rad2Deg);
      fprintf(flarray[1], "wulingweiyitengxilang %30.26lf \n",PI);


   char str1[100] = "This is ", str2[] = "programiz.com";

   // concatenates str1 and str2
   // the resultant string is stored in str1.
   strcat(str1, str2);

   puts(str1);
   puts(str2);

  char str3[20] = "C programming";
   char * str4;

   str4 = (char *) malloc(20*sizeof(char));
   // copying str1 to str2
   strcpy(str4, str3);

   puts(str4); // C programming
  char * str5;

   str5 = (char *) malloc(20*sizeof(char));
   // copying str1 to str2
   for(i=24;i<10000;i=i+2000){
   itoa(i, str5, 10);
   puts(str5); // C programming
   }



free(flarray);
    return 0;
}

