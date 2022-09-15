#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159

int main(int argc, char*argv[] )
{
    float weight;
    float volume;
    float batchWeight;
    float innerA;
    float outerA;
    float area;
    float innerD;
    float outerD;
    float thickness;
    float density;
    float quantity;

    // Pointer to innerA //
    float* PtrInA;
    
    // Pointer to outerA //
    float* PtrOutA;
    
    // Pointer to area //
    float* SolutionArea;
    
     // pointer to a pointer //
    float** SolutionArea2;
    
    // Pointer to  volume // 
    float* Solutionvol;
    
    // Pointer to weight //
    float* SolutionWeight;
    
     //pointer to a pointer as well//
    float** SolutionWeight2;
    
    // Pointer to batchWeight //
    float* SolutionBatWeight;
    
    //pointer to a pointer as well//
    float** SolutionBatWeight2;
    
    float* pointer1;
    
    float* pointer2;
    
    float* pointer3;
    
    float* pointer4;
    
    float* pointer5;
        
    if(argc == 6){
         innerD = atof(argv[1]);
         outerD = atof(argv[2]);
         thickness = atof(argv[3]);
         density = atof(argv[4]);
         quantity = atof(argv[5]);
    }
    
    else{
        printf("Please enter the Inner Diameter of the Washer in cm: ");
        scanf("%f", &innerD); //InnerDiameter
        printf("Please enter the Outer Diameter of the Washer in cm: ");
        scanf("%f", &outerD); //Outer Diameter
        printf("Please enter the density of the material of the Washer in g/cm2: ");
        scanf("%f", &density); //Density
        printf("Please enter the thickness of the Washer in cm: ");
        scanf("%f", &thickness); //Thickness
        printf("Please enter the number of washers ordered: ");
        scanf("%f", &quantity); //Quantity
        
      }
      
      // all pointers to the input
        pointer1 = &innerD;
        pointer2 = &outerD;
        pointer3 = &density;
        pointer4 = &thickness;
        pointer5 = &quantity;
      
      // //InnerA = PI*innerD/2*innerD/2;// 
        innerA = PI * pow(*pointer1/2,2);
        PtrInA = &innerA;
        
      //outerA = PI*outerD/2*outerD/2;//
        outerA =  PI * pow(*pointer2/2,2);
        PtrOutA = &outerA;
        
        //area = outerA - innerA;//
        area = *PtrOutA - *PtrInA;
        SolutionArea = &area;
        
        //volume = area * thickness;//
        volume = *SolutionArea * (*pointer4);
        Solutionvol = &volume;
        
          //  weight = volume * density;//
        weight = *Solutionvol * (*pointer3);
        SolutionWeight = &weight;
        
         // batchWeight = quantity*weight;//
        batchWeight = *pointer5 * (*SolutionWeight); 
        SolutionBatWeight = &batchWeight;
        //batchWeight = quantity*weight;
        
        // store address area to pointer area2 // 
        SolutionArea2 = &SolutionArea;
        printf("The Rim Area of the washer is %10.5f \n", **SolutionArea2);
        
         // storing adress Weight to pointer weight 2 // 
        SolutionWeight2 = &SolutionWeight;
        printf("The weight of one washer is %10.5f \n", **SolutionWeight2);
        
        // storing address batchWeight to pointer batchWeight 2 // 
         SolutionBatWeight2 = &SolutionBatWeight;
        printf("The weight of the batch of washers is %10.5f \n", **SolutionBatWeight2);
        
        // will give us all the memory of the user input or that was input in the command line //
        printf("\nMemory Address of InnerDiameter: %p ", &innerD);
        printf("\nMemory Address of OuterDiameter: %p", &outerD);
        printf("\nMemory Address of Density: %p", &density);
        printf("\nMemory Address of Thickness: %p", &thickness);
        printf("\nMemory Address of Quantity: %p \n", &quantity);
        
      
}
