#include "file.h"

void Save(AddressBook *addr)
{
    FILE *fp = fopen(File,"w");
    if(!fp)
    {
        printf("Saving failed\n");
        return;
    }
    fprintf(fp,"%d",addr->contact_count);
    for(int i=0;i<addr->contact_count;i++)
    fprintf(fp,"%s,%s,%s\n",addr->contact[i].name,addr->contact[i].ph,addr->contact[i].gmail);

    fclose(fp);
}

void Initialise(AddressBook *addr)
{
    FILE *fp = fopen(File,"r");
    if(!fp)
    {
        fp = fopen(File,"w");
        fprintf(fp,"%d\n",0);
        fclose(fp);
        fp = fopen(File,"r");
    }
    fscanf(fp,"%d\n",&addr->contact_count);
    char line[256];
    for(int i =0;i<addr->contact_count;i++)
    {
        fgets(line,sizeof(line),fp);
        sscanf(line, "%49[^,],%19[^,],%49[^\n]",addr->contact[i].name,addr->contact[i].ph,addr->contact[i].gmail);

    }
}
