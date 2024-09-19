#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>


using namespace std;

typedef struct
{
    int spellID;
    char incantation[100];
    char spell_name[100];
    char effect[100];
    char light[50];

}spell;

void Database_read(spell spells[], int *iteration)
{
    FILE*file = fopen("spells.txt" , "r" );
    if (file==NULL)
    {
        cout<<"ERROR"<<endl;
        return;
    }

    *iteration = 0;
    while (*iteration < 100 && fscanf(file, "%100s %100s %100s %100s",
                                             spells[*iteration].incantation,
                                             spells[*iteration].spell_name,
                                             spells[*iteration].effect,
                                             spells[*iteration].light) == 4) {
        (*iteration)++;
    }

    fclose(file);
}

void enterspell(spell Nspell)
{
    
        FILE*file = fopen("spells.txt","a");
        if (file==NULL)
        {
            cout<<"ERROR";
            return;
        }
        fprintf(file, "%s %s %s %s\n", Nspell.incantation, Nspell.spell_name, Nspell.effect, Nspell.light);
        fclose(file);
    
    
}
void Database_display(spell spells[], int iteration)
{
    for (int i = 0; i < iteration; i++)
    {
        cout<<"Incantation :%s" << spells[i].incantation<<endl;
        cout<<"Spell Name :%s" << spells[i].spell_name<<endl;
        cout<<"Effect :%s" << spells[i].effect<<endl;
        cout<<"Light :%s" << spells[i].light<<endl;
    }
    
}






int main() {
    int choose;
    spell Nspell;
    spell spells[1000];
    int iteration = 0;

    Database_read(spells, &iteration);

    while(1)
    {
        cout<<"Spell Database Menu"<<endl;
        cout<<"1. Show all spells"<<endl;
        cout<<"2. Insert spell"<<endl;
        cout<<"3. Update spell"<<endl;
        cout<<"4. Delete spell"<<endl;
        cout<<"5. Search spell"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter choice:"<<endl;
        cin>>choose;
    }

    switch(choose)
    {
        case 1:
        Database_display(spells,iteration);
        break;
        case 2:
        cout<<"Enter Incantation : ";
        cin>>Nspell.incantation;
        cout<<"Enter Spell Name : ";
        cin>>Nspell.spell_name;
        cout<<"Enter Spell Effect : ";
        cin>>Nspell.effect;
        cout<<"Enter Spell Light : ";
        cin>>Nspell.light;
        enterspell(Nspell);
        break;
        case 3:
        return 0;

        default:
        cout<<"Sorry"<<endl;
        break;

    }
    
    return 0;
}