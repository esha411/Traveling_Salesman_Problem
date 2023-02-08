#include<stdio.h>
#include<string.h>
//stores the city names
char city_names[10][50];
//to store starting city
int inum;
int arr[10][10], done[10], n, cost=0;
int result[10],index=0;
int mileage, tankcapa;

void input()
{
	int i, k;
    printf("Enter the number of cities: ");
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		printf("Enter the %dth city: ", i+1);
		//takes in city names
		scanf(" %[^\n]", city_names[i]);
	}
	printf("\nEnter the cost matrix\n");
	for(i=0;i<n-1;i++)
	{
		printf("\nEnter elements of row %d as per the cost matrix\n",i+1);
		for(k=i+1;k<n;k++)
		{
		    //checks for same city
			if(i==k)
                 //assigning same city as 0
				arr[i][k]=0;
			else
			{
				printf("Enter the distance between %s and %s: ", city_names[i], city_names[k]);
                //taking distance between cities
				scanf("%d", &arr[i][k]);
				//distance between A and B is equal to distance between B and A
				arr[k][i]=arr[i][k];
			}
		}
		//to make visited =0
		done[i]=0;
	}
	printf("\nEnter the mileage of your car (in km/lit): ");
	scanf("%d",&mileage);
	printf("Enter the tank capacity of your car (in lit): ");
    scanf("%d",&tankcapa);
	printf("\nThe cost matrix is:\n");
	//printing the cost matrix
    for(i=0;i<n;i++)
	{
        for(k=0;k<n;k++)
        {
        	printf("\t%d", arr[i][k]);
		}
		printf("\n");
	}
}

void calc(int city)
{
	int nex_city;
	//marking the city which has been already visited
	done[city]=1;
	//printing
	printf("%s--->", city_names[city]);
	result[index]=city;
	//storeing the final path in another array
	index++;
	//searching for the nearest city
	nex_city=least_city(city);
	//chekcing if the cycle is complete
	if(nex_city==999999)
	{
		nex_city=inum-1;
		printf("%s", city_names[nex_city]);
		result[index]=nex_city;
		index++;
		cost+=arr[city][nex_city];
		return;
	}
	 //going to the next node
	calc(nex_city);
}

int least_city(int i)
{
	int temp=999999, k, nc=999999;
	for(k=0;k<n;k++)
	{
	    //checking if its a different node and weather its visited or not
		if((arr[i][k]!=0)&&(done[k]==0))
		{
		    //checking if its the nearest city or not
			if(arr[i][k]<temp)
			{
			    //storing the running nearest city
				temp=arr[i][k];
				nc=k;
			}
		}
	}
	//if next city is found
	if(temp!=999999)
	{
	    //incriment the distance travelled
		cost+=temp;
	}
	//return next city
	return nc;
}

void refuel()
{
    int distancecapa=mileage*tankcapa;
    int dist=0;
    if(cost<=distancecapa)
    {
        printf("No refueling required in the whole journey.\n");
    }
    else
    {
        //int no of times refuel=cost/distancecapa+1;
        //for(int i=0;i<no of times refuel;i++)
        {
            for(int j=0;j<n;j++)
            {
                dist=dist+arr[result[j]][result[j+1]];
                if(dist>distancecapa)
                {
                    dist=0;
                    printf("Refueling must be done between cities %s and %s cities.\n",city_names[result[j]],city_names[result[j+1]]);
                    j--;
                    //continue;
                }
            }
        }
    }
}

void main()
{
	int i;
	input();
	printf("\nEnter the number of the starting city: ");
	scanf("%d", &inum);
	printf("The path is\n");
	calc(inum-1);

	printf("\nMinimum distance required to travel is %d\n",cost);
	refuel();
    getch();
}
