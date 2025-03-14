#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>

#define METRICTON 3527392
#define METRICFAC 0.0000283495

enum Choice {
    ADD,
    CLOSE,
    };
    
struct CerealBox {
    double Weight_Ounces;
    double Weight_Tons;
    double CerealBoxesToTons;

    double Get_Weight() {
        Weight_Tons = Weight_Ounces * METRICFAC;
        return Weight_Tons;
        }
    
    double Get_Max() {
        Weight_Tons = Get_Weight();
        CerealBoxesToTons = METRICTON / Weight_Tons;
        return CerealBoxesToTons;
        }
};

struct Boxes {
    std::vector<CerealBox> Cereal;
    double TotalWeight;
    };
    
    
int main() {
    int choice;
    Boxes cluster;
    cluster.TotalWeight = 0.0;
    while (true) {
        puts("Options\n=======");
        puts("\n(0) Add another box");
        puts("\n(1) Quit");
        scanf("%d", &choice);
        switch (choice) {
            case ADD:
                CerealBox box;
                puts("\nWeight in oz\n");
                scanf("%lf", &box.Weight_Ounces);
                box.Get_Weight();
                box.Get_Max();
                cluster.TotalWeight += box.Weight_Tons; 
                cluster.Cereal.push_back(box);
                break;
                
            case CLOSE:
                printf("The cluser is %lf metric tons.", cluster.TotalWeight);
                break;
                }
        if (choice == CLOSE) {
            break;
            }
            }
        return 0;
        }
