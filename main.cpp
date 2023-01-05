#include "MLL.h"

int main()
{
    struct l1 bahasa = initL1();
    struct l3 kategori = initL3();
    struct vertex* p;
    struct edge* r;

    bahasa = initL1();
    p = initVertex("Phyton");
    insertLastL1(bahasa, p);
    p = initVertex("Java");
    insertLastL1(bahasa, p);
    p = initVertex("C++");
    insertLastL1(bahasa, p);

    kategori = initL3();
    r = initEdge("scripting");
    insertLastL3(kategori, r);
    r = initEdge("procedural");
    insertLastL3(kategori, r);
    r = initEdge("oop");
    insertLastL3(kategori, r);
    r = initEdge("compiled");
    insertLastL3(kategori, r);

    linkVertexEdge(bahasa, kategori, "Phyton", "scripting");
    linkVertexEdge(bahasa, kategori, "Phyton", "procedural");
    linkVertexEdge(bahasa, kategori, "Phyton", "oop");

    linkVertexEdge(bahasa, kategori, "Java", "compiled");
    linkVertexEdge(bahasa, kategori, "Java", "procedural");
    linkVertexEdge(bahasa, kategori, "Java", "oop");

    linkVertexEdge(bahasa, kategori, "C++", "compiled");
    linkVertexEdge(bahasa, kategori, "C++", "oop");

    //std::cout << "\033[1;30mHello, World!\033[0m" << std::endl;  // grey
    //std::cout << "\033[1;31mHello, World!\033[0m" << std::endl;  // red
    //std::cout << "\033[1;32mHello, World!\033[0m" << std::endl;  // green
    //std::cout << "\033[1;33mHello, World!\033[0m" << std::endl;  // yellow
    //std::cout << "\033[1;34mHello, World!\033[0m" << std::endl;  // blue
    //std::cout << "\033[1;35mHello, World!\033[0m" << std::endl;  // purple
    //std::cout << "\033[1;36mHello, World!\033[0m" << std::endl;  // cyan
    //std::cout << "\033[1;37mHello, World!\033[0m" << std::endl;  // white

    int selection = {20};
    string info1;
    string info2;

    while (selection != 0) {

        cout << "==============================================================\n";
        //cout << "l1 = vertex = parent = bahasa\n";
        //cout << "l2 = link = -\n";
        //cout << "l3 = edge = child = kategori   \n\n";

        cout << "0. Exit\n";
        cout << "1. Tambahkan data pada parent\n";
        cout << "2. Tambahkan data pada child\n";
        cout << "3. Tampilkan data pada parent\n";
        cout << "4. Tampilkan data pada child\n";
        cout << "5. Hubungkan parent dengan child\n";
        cout << "6. Putuskan parent dengan child\n";
        cout << "7. Hapus parent\n";    //akan menghapus data linknya
        cout << "8. Hapus child\n";     //akan menghapus data linknya
        cout << "9. Hitung jumlah child pada parent\n";
        cout << "10. Tampilkan parent dengan child terbanyak\n";
        cout << "11. Tampilkan parent dengan child tersedikit\n";
        cout << "==============================================================\n\n";
        cout << "Masukkan pilihan > ";

        cin >> selection;

        switch (selection) {
        case 1:
            cout << "Masukkan nama > ";
            cin >> info1;
            insertLastL1(bahasa, initVertex(info1));
            break;
        case 2:
            cout << "Masukkan nama > ";
            cin >> info1;
            insertLastL3(kategori, initEdge(info1));
            break;
        case 3:
            showL1(bahasa);
            std::cout << "Click any key to continue...";
            _getch();
            break;
        case 4:
            showL3(kategori);
            std::cout << "Click any key to continue...";
            _getch();
            break;
        case 5:
            cout << "Masukkan nama parent > ";
            cin >> info1;
            cout << "Masukkan nama child > ";
            cin >> info2;
            linkVertexEdge(bahasa, kategori, info1, info2);
            break;
        case 6:
            cout << "Masukkan nama parent > ";
            cin >> info1;
            cout << "Masukkan nama child > ";
            cin >> info2;
            deleteLink(bahasa, info1, info2);
            break;
        case 7:
            cout << "Masukkan nama > ";
            cin >> info1;
            deleteVertex(bahasa, info1);
            break;
        case 8:
            cout << "Masukkan nama > ";
            cin >> info1;
            deleteEveryLink(bahasa, info1);
            deleteEdge(kategori, info1);
            break;
        case 9:
            cout << "Masukkan nama > ";
            cin >> info1;
            cout << "Terdapat " << countLink(bahasa, info1) << " child pada " << info1 << endl;
            std::cout << "Click any key to continue...";
            _getch();
            break;
        case 10:
            cout << "Parent dengan child terbanyak adalah " << searchMostLink(bahasa)->info << endl;
            std::cout << "Click any key to continue...";
            _getch();
            break;
        case 11:
            cout << "Parent dengan child tersedikit adalah " << searchLeastLink(bahasa)->info << endl;
            std::cout << "Click any key to continue...";
            _getch();
            break;
        }
        system("cls");
    }
}

