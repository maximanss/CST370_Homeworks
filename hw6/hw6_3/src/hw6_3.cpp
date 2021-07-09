/*
 * Title: hw6_3.cpp
 * Abstract: This program use Floyd Algoritm to find the shortest distance
 *			between pair of the vertices in the given graph from user
 *			
 * Author: Max Halbert
 * ID: 3636
 * Date: 12/14/2020
 */
 
 #include <iostream>
 #include <vector>
 using namespace std;
 
 #define INF -1

// Solves the all-pairs shortest path  
// problem using Floyd algorithm  
void floyd (vector<vector<int>> & g, int v)  
{  
    
    int i, j, k; 
  
    
    for (k = 0; k < v; k++)  
    {  
        for (i = 0; i < v; i++)  
        {  
        	// Pick all vertices as source one by one  other than k
        	if (i != k)
        	{
           
            	for (j = 0; j < v; j++)  
            	{  
                	if (j != k && i != j)
                	{
                		// calculate the shorter distance based on the vertice k
                		if (g[i][k] != INF && g[k][j] != INF)
                		{
                			if (g[i][j] == INF || (g[i][k] + g[k][j] < g[i][j]))
                				g[i][j] = g[i][k] + g[k][j];
                			
                		}
            		}  
        		}		  
    		} 
        }
    }
  
    
}  
  
/* Print the distance values between vertices in the graph */
void printGraph(vector<vector<int>> & g, int v)  
{  
     
    for (int i = 0; i < v; i++)  
    {  
        for (int j = 0; j < v; j++)  
        {  
        	cout<< g[i][j] <<" ";  
        }  
        cout << endl;  
    }  
}  
  
// Driver code  
int main()  
{  
    int vertices;
    cin >> vertices;
    int num;
    
    vector<vector<int>> graph(vertices);
    for (int i = 0; i < vertices; i++ )
    	graph[i] = vector<int>(vertices);
    
    // read the edge value of the vertices in the graph
    for(int row = 0; row < vertices; row++)
    {
    	for (int col = 0; col < vertices; col++)
    	{
    		cin >> num;
    		graph[row][col] = num; 
    		
    	}
    }
    
    floyd(graph, vertices);
    
    printGraph(graph, vertices);
    
    return 0;  
}  