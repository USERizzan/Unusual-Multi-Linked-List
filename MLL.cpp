#include "MLL.h"

l1 initL1() {
	struct l1 temp;
	temp.head = { NULL };
	return temp;
}
vertex* initVertex(string info) {
	struct vertex* temp = new vertex;
	temp->info = { info };
	temp->child = { NULL };
	temp->next = { NULL };

	return temp;
}
void insertLastL1(l1& l1, vertex* p) {
	if (l1.head == NULL) {
		l1.head = p;
	}
	else {
		struct vertex* temp = { l1.head };
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = p;
	}
}
vertex* searchVertex(l1 l1, string info) {
	struct vertex* temp = l1.head;

	while (temp != NULL) {
		if (temp->info == info) {
			return temp;
		}
		temp = temp->next;
	}

	return NULL;
}
void showL1(l1 l1) {
	struct vertex* temp = l1.head;

	while (temp != NULL) {
		cout << temp->info;

		if (temp->child != NULL) {
			cout << ": ";
			link* buffer = temp->child;
			while (buffer != NULL) {
				cout << buffer->info->info << ", ";
				buffer = buffer->next;
			}
		}

		cout << endl;
		temp = temp->next;
	}
	cout << endl;
}
void deleteFirstVertex(l1& l1) {
	struct vertex* temp = l1.head;
	struct vertex* buffer;
	buffer = temp;
	temp = temp->next;
	l1.head = temp;

	while (buffer->child != NULL)
		deleteFirstLink(buffer);

	delete buffer;
}
void deleteMidVertex(l1& l1, vertex* p) {
	struct vertex* temp = l1.head;
	struct vertex* buffer;

	while (temp->next != p) {
		temp = temp->next;
	}
	buffer = temp->next;
	temp->next = temp->next->next;

	while (buffer->child != NULL)
		deleteFirstLink(buffer);

	delete buffer;
}
void deleteLastVertex(l1& l1) {
	struct vertex* temp = l1.head;
	struct vertex* buffer;

	while (temp->next->next != NULL) {
		temp = temp->next;
	}
	buffer = temp->next;
	temp->next = NULL;

	while (buffer->child != NULL)
		deleteFirstLink(buffer);

	delete buffer;
}
void deleteVertex(l1& l1, string info) {
	struct vertex* temp = searchVertex(l1, info);

	if (temp != NULL) {
		if (l1.head == temp)			deleteFirstVertex(l1);
		else if (temp->next == NULL)	deleteLastVertex(l1);
		else							deleteMidVertex(l1, temp);
	}
}
int countVertex(l1& l1) {
	struct vertex* temp = l1.head;
	int counter = { 0 };

	while (temp != NULL) {
		temp = temp->next;
		++counter;
	}

	return counter;
}
vertex* searchMostLink(l1 l1) {
	vertex* mostVertex = l1.head;
	int mostNum = countLink(l1, l1.head->info);

	if (l1.head->next != NULL) {
		vertex* temp = l1.head->next;

		while (temp != NULL) {
			if (temp->child != NULL) {
				if (mostNum < countLink(l1, temp->info)) {
					mostVertex = temp;
					mostNum = countLink(l1, temp->info);
				}
			}
			temp = temp->next;
		}
	}

	return mostVertex;
}
vertex* searchLeastLink(l1 l1) {
	vertex* leastVertex = l1.head;
	int leastNum = countLink(l1, l1.head->info);

	if (l1.head->next != NULL) {
		vertex* temp = l1.head->next;

		while (temp != NULL) {
			if (temp->child != NULL) {
				if (leastNum > countLink(l1, temp->info)) {
					leastVertex = temp;
					leastNum = countLink(l1, temp->info);
				}
			}
			temp = temp->next;
		}
	}

	return leastVertex;
}
void deleteEveryLink(l1& l1, string infoLink) {
	struct vertex* temp = l1.head;

	while (temp != NULL) {
		deleteLink(l1, temp->info, infoLink);
		temp = temp->next;
	}
}


link* initLink(linkInfo info) {
	struct link* temp = new link;
	temp->info = info;
	temp->next = NULL;

	return temp;
}
void insertLastLink(vertex* p, link* q) {
	if (p->child == NULL) {
		p->child = q;
	}
	else {
		struct link* temp = p->child;
		while (temp->next != NULL) {
			temp->next;
		}
		temp->next = q;
	}
}
link* searchLink(vertex* p, string info) {
	if (p != NULL) {
		struct link* temp = p->child;

		while (temp != NULL) {
			if (temp->info->info == info) {
				return temp;
			}
			temp = temp->next;
		}
	}
	return NULL;
}
void linkVertexEdge(l1 l1, l3 l3, string bahasa, string kategori) {
	vertex* p = searchVertex(l1, bahasa);
	edge* r = searchEdge(l3, kategori);

	if ((p != NULL) || (r != NULL)) {
		struct link* temp = initLink(r);

		if (p->child == NULL) {
			p->child = temp;
		}
		else {
			struct link* buffer = p->child;
			while (buffer->next != NULL) {
				buffer = buffer->next;
			}
			buffer->next = temp;
		}
	}
}
void deleteFirstLink(vertex* p) {
	struct link* temp = p->child;
	struct link* buffer;
	buffer = temp;
	temp = temp->next;
	p->child = temp;
	delete buffer;
}
void deleteMidLink(vertex* p, link* q) {
	struct link* temp = p->child;
	struct link* buffer;

	while (temp->next != q) {
		temp = temp->next;
	}
	buffer = temp->next;
	temp->next = temp->next->next;
	delete buffer;
}
void deleteLastLink(vertex* p) {
	struct link* temp = p->child;
	struct link* buffer;

	while (temp->next->next != NULL) {
		temp = temp->next;
	}
	buffer = temp->next;
	temp->next = NULL;
	delete buffer;
}
void deleteLink(l1& l1, string infoVertex, string infolink) {
	struct vertex* temp = searchVertex(l1, infoVertex);
	struct link* buffer = searchLink(temp, infolink);

	if (buffer != NULL) {
		if (temp->child == buffer)			deleteFirstLink(temp);
		else if (buffer->next == NULL)		deleteLastLink(temp);
		else								deleteMidLink(temp, buffer);
	}
}
int countLink(l1 l1, string info) {
	int counter = { 0 };
	struct vertex* temp = searchVertex(l1, info);

	if (temp != NULL) {
		struct link* buffer = temp->child;

		while (buffer != NULL) {
			buffer = buffer->next;
			++counter;
		}
	}

	return counter;
}


l3 initL3() {
	struct l3 temp;
	temp.head = { NULL };
	return temp;
}
edge* initEdge(string info) {
	struct edge* temp = new edge;
	temp->info = { info };
	temp->next = { NULL };

	return temp;
}
void insertLastL3(l3& l3, edge* r) {
	if (l3.head == NULL) {
		l3.head = r;
	}
	else {
		struct edge* temp = { l3.head };
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = r;
	}
}
edge* searchEdge(l3 l3, string info) {
	struct edge* temp = l3.head;

	while (temp != NULL) {
		if (temp->info == info) {
			return temp;
		}
		temp = temp->next;
	}

	return NULL;
}
void showL3(l3 l3) {
	struct edge* temp = l3.head;

	while (temp != NULL) {
		cout << temp->info << ", ";
		temp = temp->next;
	}
	cout << "\n\n";
}
void deleteFirstEdge(l3& l3) {
	struct edge* temp = l3.head;
	temp = temp->next;
	l3.head = temp;
}
void deleteMidEdge(l3& l3, edge* r) {
	struct edge* temp = l3.head;

	while (temp->next != r) {
		temp = temp->next;
	}

	temp->next = temp->next->next;
}
void deleteLastEdge(l3& l3) {
	struct edge* temp = l3.head;

	while (temp->next->next != NULL) {
		temp = temp->next;
	}

	temp->next = NULL;
}
void deleteEdge(l3& l3, string info) {
	struct edge* temp = searchEdge(l3, info);


	if (temp != NULL) {
		if (l3.head == temp)			deleteFirstEdge(l3);
		else if (temp->next == NULL)	deleteLastEdge(l3);
		else							deleteMidEdge(l3, temp);
	}
}