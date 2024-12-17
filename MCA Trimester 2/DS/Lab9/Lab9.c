#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

typedef struct Graph
{
    int numVertices;
    Node **adjLists;
    int *visited;
} Graph;

Node *createNode(int);
Graph *createGraph(int);
void addEdge(Graph *, int, int);
void BFT(Graph *, int, int);
void DFT(Graph *, int, int);
void DFTUtil(Graph *, int, int, int *);

int main()
{
    int vertices, edges, startVertex, searchVertex;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    Graph *graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < edges; i++)
    {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Enter the starting vertex for traversal: ");
    scanf("%d", &startVertex);

    printf("Enter the vertex to search for: ");
    scanf("%d", &searchVertex);

    printf("Breadth-First Traversal:\n");
    BFT(graph, startVertex, searchVertex);

    printf("Depth-First Traversal:\n");
    DFT(graph, startVertex, searchVertex);

    return 0;
}

Node *createNode(int v)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph *createGraph(int vertices)
{
    Graph *graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(Node *));
    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(Graph *graph, int src, int dest)
{
    Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void BFT(Graph *graph, int startVertex, int searchVertex)
{
    int *visited = malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++)
        visited[i] = 0;

    int queue[MAX], front = 0, rear = 0;
    queue[rear++] = startVertex;
    visited[startVertex] = 1;

    while (front < rear)
    {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        if (currentVertex == searchVertex)
        {
            printf("\nVertex %d found!\n", searchVertex);
            free(visited);
            return;
        }

        Node *temp = graph->adjLists[currentVertex];
        while (temp)
        {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex])
            {
                queue[rear++] = adjVertex;
                visited[adjVertex] = 1;
            }
            temp = temp->next;
        }
    }

    printf("\nVertex %d not found.\n", searchVertex);
    free(visited);
}

void DFT(Graph *graph, int startVertex, int searchVertex)
{
    int *visited = malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++)
        visited[i] = 0;

    DFTUtil(graph, startVertex, searchVertex, visited);
    free(visited);
}

void DFTUtil(Graph *graph, int vertex, int searchVertex, int *visited)
{
    visited[vertex] = 1;
    printf("%d ", vertex);

    if (vertex == searchVertex)
    {
        printf("\nVertex %d found!\n", searchVertex);
        return;
    }

    Node *temp = graph->adjLists[vertex];
    while (temp)
    {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex])
            DFTUtil(graph, adjVertex, searchVertex, visited);
        temp = temp->next;
    }
}