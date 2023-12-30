#ifndef PRGS2_H_INCLUDED
#define PRGS2_H_INCLUDED

#include <iostream>
#include <string>
#define info(P) (P)->info
#define next(P) (P)->next
#define jadwalP(Q) (Q)->jadwalP
#define first(L) ((L).first)

using namespace std;

typedef struct elemenDriver *adr_driver;
typedef struct elemenCustomer *adr_customer;
typedef struct elemenRelation *adr_relation;
typedef struct Driver infotypeDriver;
typedef struct Customer infotypeCustomer;
typedef struct Relation infotypeRelation;

// Struktur data untuk Parent (Driver)
struct Driver {
    int id;
    string nama;
    string noHP;
    string kendaraan;
    string noKendaraan;
    double rating;
    int jlCust;
};

// Struktur data untuk Child (Customer)
struct Customer {
    int id;
    string nama;
    string noHP;
    string alamat;
    int jlTransaksi;
    string layanan[10];
};

// Struktur data untuk Relasi
struct Relation {
    int driverId;
    int customerId;
};

struct elemenDriver {
    infotypeDriver info;
    adr_driver next;
};

struct elemenCustomer {
    infotypeCustomer info;
    adr_customer next;
};

struct elemenRelation {
    infotypeRelation info;
    adr_relation next;
};

struct listDriver {
    adr_driver first;
};

struct listCustomer {
    adr_customer first;
};

struct listRelation {
    adr_relation first;
};

// a. Insert element parent
void insertDriver(listDriver &L, infotypeDriver x);

// b. Insert element child
void insertCustomer(listCustomer &L, infotypeCustomer x) ;

// c. Insert element relation
void insertRelation(listRelation &L, infotypeRelation x) ;

// d. Delete element parent
void deleteDriver(listDriver &L, int id) ;

// e. Delete element child
void deleteCustomer(listCustomer &L, int id) ;

// f. Delete element relation
void deleteRelation(listRelation &L, int driverId, int customerId) ;

// g. Find element Parent
adr_driver findDriver(listDriver L, int id) ;

// h. Find element child
adr_customer findCustomer(listCustomer L, int id) ;

// i. Find apakah parent dan child tertentu memiliki relasi
adr_relation findRelation(listRelation L, int driverId, int customerId) ;

// j. Show all data di List Parent
void showAllDrivers(listDriver L) ;

// k. Show all data di List Child
void showAllCustomers(listCustomer L) ;

// l. Show data child dari parent tertentu
void showCustomersOfDriver(listRelation LR, listCustomer LC, int driverId) ;


#endif // PRGS2_H_INCLUDED
