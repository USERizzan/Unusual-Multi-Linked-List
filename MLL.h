#pragma once

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
using namespace std;

typedef string vertexInfo;
typedef struct edge* linkInfo;
typedef string edgeInfo;

struct vertex {
	vertexInfo info;
	struct link* child;
	vertex* next;
};

struct link {
	linkInfo info;
	struct link* next;
};

struct edge {
	edgeInfo info;
	struct edge* next;
};

struct l1 {
	struct vertex* head;
};

struct l3 {
	struct edge* head;
};

l1 initL1();
vertex* initVertex(string info);
void insertLastL1(l1& l1, vertex* p);
vertex* searchVertex(l1 l1, string info);
void showL1(l1 l1);
void deleteLastVertex(l1& l1);
void deleteFirstVertex(l1& l1);
void deleteMidVertex(l1& l1, vertex* p);
void deleteVertex(l1& l1, string p);
int countVertex(l1& l1);
vertex* searchMostLink(l1 l1);
vertex* searchLeastLink(l1 l1);
void deleteEveryLink(l1& l1, string infoLink);

link* initLink(linkInfo info);
void insertLink(vertex* p, link* q);
void linkVertexEdge(l1 l1, l3 l3, string bahasa, string kategori);
void deleteFirstLink(vertex* p);
void deleteMidLink(vertex* p, link* q);
void deleteLastLink(vertex* p);
void deleteLink(l1& l1, string infoVertex, string infolink);
int countLink(l1 l1, string info);

l3 initL3();
edge* initEdge(string info);
void insertLastL3(l3& l3, edge* r);
edge* searchEdge(l3 l3, string info);
void showL3(l3 l3);
void deleteFirstEdge(l3& l3);
void deleteMidEdge(l3& l3, edge* p);
void deleteLastEdge(l3& l3);
void deleteEdge(l3& l3, string p);