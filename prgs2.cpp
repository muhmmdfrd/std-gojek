#include "prgs2.h"

// a. Insert element parent
void insertDriver(listDriver &L, infotypeDriver x) {
    adr_driver P = new elemenDriver;
    info(P) = x;
    next(P) = NULL;

    if (first(L) == NULL) {
        first(L) = P;
    } else {
        adr_driver Q = first(L);
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

// b. Insert element child
void insertCustomer(listCustomer &L, infotypeCustomer x) {
    adr_customer P = new elemenCustomer;
    info(P) = x;
    next(P) = NULL;

    if (first(L) == NULL) {
        first(L) = P;
    } else {
        adr_customer Q = first(L);
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
    }

    if (info(P).jlTransaksi > 0 && info(P).jlTransaksi <= 10) {
        for (int i = 0; i < info(P).jlTransaksi; i++) {
            if (i < 10) {
                info(P).layanan[i] = x.layanan[i];
            } else {
                break;
            }
        }
    }
}

// c. Insert element relation
void insertRelation(listRelation &L, infotypeRelation x) {
    adr_relation P = new elemenRelation;
    info(P) = x;
    next(P) = NULL;

    if (first(L) == NULL) {
        first(L) = P;
    } else {
        adr_relation Q = first(L);
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

// d. Delete element parent
void deleteDriver(listDriver &L, int id) {
    adr_driver P = first(L);
    adr_driver Prec = NULL;
    while (P != NULL && info(P).id != id) {
        Prec = P;
        P = next(P);
    }
    if (P != NULL) {
        if (Prec == NULL) {
            first(L) = next(P);
        } else {
            next(Prec) = next(P);
        }
        delete P;
        cout << "Driver berhasil dihapus." << endl;
    } else {
        cout << "Driver tidak ditemukan. Penghapusan gagal." << endl;
    }
}

// e. Delete element child
void deleteCustomer(listCustomer &L, int id) {
    adr_customer P = first(L);
    adr_customer Prec = NULL;
    while (P != NULL && info(P).id != id) {
        Prec = P;
        P = next(P);
    }
    if (P != NULL) {
        if (Prec == NULL) {
            first(L) = next(P);
        } else {
            next(Prec) = next(P);
        }
        delete P;
        cout << "Customer berhasil dihapus." << endl;
    } else {
        cout << "Customer tidak ditemukan. Penghapusan gagal." << endl;
    }
}

// f. Delete element relasi
void deleteRelation(listRelation &L, int driverId, int customerId) {
    adr_relation P = first(L);
    adr_relation Prec = NULL;

    while (P != NULL && (info(P).driverId != driverId || info(P).customerId != customerId)) {
        Prec = P;
        P = next(P);
    }

    if (P != NULL) {
        if (Prec == NULL) {
            first(L) = next(P);
        } else {
            next(Prec) = next(P);
        }
        delete P;
        cout << "Relasi berhasil dihapus." << endl;
    } else {
        cout << "Relasi tidak ditemukan. Penghapusan gagal." << endl;
    }
}

// g. Find element Parent
adr_driver findDriver(listDriver L, int id) {
    adr_driver P = first(L);
    while (P != NULL && info(P).id != id) {
        P = next(P);
    }
    return P;
}

// h. Find element Child
adr_customer findCustomer(listCustomer L, int id) {
    adr_customer P = first(L);
    while (P != NULL && info(P).id != id) {
        P = next(P);
    }
    return P;
}

// i. Find apakah driver dan customer tertentu memiliki relasi
adr_relation findRelation(listRelation L, int driverId, int customerId) {
    adr_relation P = first(L);
    while (P != NULL && (info(P).driverId != driverId || info(P).customerId != customerId)) {
        P = next(P);
    }
    if (P != NULL) {
        cout << "Ada relasi antara driver ID " << info(P).driverId << " dan customer ID " << info(P).customerId << "." << endl;
    } else {
        cout << "Tidak ada relasi antara driver ID " << driverId << " dan customer ID " << customerId << "." << endl;
    }
    return P;
}

// j. Show all data di List Parent
void showAllDrivers(listDriver L) {
    adr_driver P = first(L);

    cout << "=================D R I V E R S=================" << endl;
    while (P != NULL) {
        cout << "ID: " << info(P).id << endl;
        cout << "Nama: " << info(P).nama << endl;
        cout << "No HP: " << info(P).noHP << endl;
        cout << "Kendaraan: " << info(P).kendaraan << endl;
        cout << "No Kendaraan: " << info(P).noKendaraan << endl;
        cout << "Rating: " << info(P).rating << endl;
        cout << "Jumlah Customer: " << info(P).jlCust << endl;
        P = next(P);
    }
    cout << "===========================================" << endl;
}

// k. Show all data di List Child

// l. Show data customer dari driver tertentu
void showCustomersOfDriver(listRelation LR, listCustomer LC, int driverId) {
    adr_relation P = first(LR);
    int customerNumber = 1;

    cout << "========== Customer Driver " << driverId << " ===========" << endl;

    bool foundDriver = false;

    while (P != NULL) {
        if (info(P).driverId == driverId) {
            adr_customer C = findCustomer(LC, info(P).customerId);
            if (C != NULL) {
                cout << "Customer ke-" << customerNumber << " :" << endl;
                cout << "ID: " << info(C).id << endl;
                cout << "Nama: " << info(C).nama << endl;
                cout << "No. HP: " << info(C).noHP << endl;
                cout << "Alamat: " << info(C).alamat << endl;
                cout << "Jumlah Transaksi: " << info(C).jlTransaksi << endl;
                cout << "Layanan: ";
                for (int i = 0; i < info(C).jlTransaksi; i++) {
                    cout << "layanan ke-" << i + 1 << " : " << info(C).layanan[i] << " ";
                }
                cout << endl;

                customerNumber++;
            }
            foundDriver = true;
        }
        P = next(P);
    }

    if (!foundDriver) {
        cout << "Driver dengan ID " << driverId << " tidak memiliki customer." << endl;
    }

    cout << "==========================================================" << endl;
}
