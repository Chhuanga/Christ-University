#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100
#define MIN_VERTICES 1

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

// Function prototypes
Node *createNode(int);
Graph *createGraph(int);
int validateVertex(Graph *graph, int vertex);
int addEdge(Graph *graph, int src, int dest);
void BFT(Graph *graph, int startVertex, int searchVertex);
void DFT(Graph *graph, int startVertex, int searchVertex);
void DFTUtil(Graph *graph, int vertex, int searchVertex, int *visited);
void freeGraph(Graph *graph);

int main()
{
    int vertices, edges, startVertex, searchVertex;

    printf("Enter the number of vertices (1-%d): ", MAX);
    if (scanf("%d", &vertices) != 1 || vertices < MIN_VERTICES || vertices > MAX)
    {
        printf("Error: Invalid number of vertices. Must be between %d and %d.\n",
               MIN_VERTICES, MAX);
        return EXIT_FAILURE;
    }

    Graph *graph = createGraph(vertices);
    if (!graph)
    {
        printf("Error: Failed to create graph.\n");
        return EXIT_FAILURE;
    }

    int maxEdges = vertices * (vertices - 1) / 2;
    printf("Enter the number of edges (0-%d): ", maxEdges);
    if (scanf("%d", &edges) != 1 || edges < 0 || edges > maxEdges)
    {
        printf("Error: Invalid number of edges. Must be between 0 and %d.\n", maxEdges);
        freeGraph(graph);
        return EXIT_FAILURE;
    }

    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < edges; i++)
    {
        int src, dest;
        if (scanf("%d %d", &src, &dest) != 2)
        {
            printf("Error: Invalid input format for edge.\n");
            freeGraph(graph);
            return EXIT_FAILURE;
        }

        if (!addEdge(graph, src, dest))
        {
            printf("Error: Invalid edge (%d, %d). Vertices must be between 0 and %d.\n",
                   src, dest, vertices - 1);
            freeGraph(graph);
            return EXIT_FAILURE;
        }
    }

    printf("Enter the starting vertex for traversal: ");
    if (scanf("%d", &startVertex) != 1 || !validateVertex(graph, startVertex))
    {
        printf("Error: Invalid starting vertex.\n");
        freeGraph(graph);
        return EXIT_FAILURE;
    }

    printf("Enter the vertex to search for: ");
    if (scanf("%d", &searchVertex) != 1 || !validateVertex(graph, searchVertex))
    {
        printf("Error: Invalid search vertex.\n");
        freeGraph(graph);
        return EXIT_FAILURE;
    }

    printf("\nBreadth-First Traversal:\n");
    BFT(graph, startVertex, searchVertex);

    printf("\nDepth-First Traversal:\n");
    DFT(graph, startVertex, searchVertex);

    freeGraph(graph);
    return EXIT_SUCCESS;
}

int validateVertex(Graph *graph, int vertex)
{
    return (vertex >= 0 && vertex < graph->numVertices);
}

int addEdge(Graph *graph, int src, int dest)
{
    if (!validateVertex(graph, src) || !validateVertex(graph, dest))
    {
        return 0;
    }

    // Check for self-loops
    if (src == dest)
    {
        printf("Warning: Self-loops are not allowed.\n");
        return 0;
    }

    // Check if edge already exists
    Node *temp = graph->adjLists[src];
    while (temp)
    {
        if (temp->vertex == dest)
        {
            printf("Warning: Edge (%d, %d) already exists.\n", src, dest);
            return 0;
        }
        temp = temp->next;
    }

    Node *newNode = createNode(dest);
    if (!newNode)
    {
        return 0;
    }
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    if (!newNode)
    {
        return 0;
    }
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;

    return 1;
}

// Memory cleanup function
void freeGraph(Graph *graph)
{
    if (graph)
    {
        if (graph->adjLists)
        {
            for (int i = 0; i < graph->numVertices; i++)
            {
                Node *current = graph->adjLists[i];
                while (current)
                {
                    Node *temp = current;
                    current = current->next;
                    free(temp);
                }
            }
            free(graph->adjLists);
        }
        if (graph->visited)
        {
            free(graph->visited);
        }
        free(graph);
    }
}
