#include <QApplication>
#include "View/MainWindow.h"
#include "Programming.h"
#include "VipPriceSeat.h"
#include "DiscountedPriceSeat.h"
#include "UnavailableSeat.h"

int main(int argc, char *argv[])
{
    Programming p;

    // Creazione dei film
    Film film1("The Lord of the Rings: The Fellowship of the Ring", "Peter Jackson", "Elijah Wood, Ian McKellen, Viggo Mortensen", 180, "An epic adventure in Tolkien's fantasy world.");
    Film film2("Inception", "Christopher Nolan", "Leonardo DiCaprio, Joseph Gordon-Levitt, Ellen Page", 150, "A science fiction film about deception and dream reality.");
    Film film3("Mission: Impossible - Dead Reckoning - Part One", "Christopher McQuarrie", "Tom Cruise, Hayley Atwell, Ving Rhames", 163, "Ethan Hunt and his IMF team race against time to stop a deadly weapon while facing personal demons and a formidable enemy.");
    Film film4("John Wick 4", "Chad Stahelski", "Keanu Reeves, Donnie Yen, Shamier Anderson", 169, "John Wick hides underground in New York with the King of Bowery to seek revenge against the High Table.");
    Film film5("Oppenheimer", "Christopher Nolan", "Cillian Murphy, Emily Blunt, Matt Damon", 181, "J. Robert Oppenheimer leads the Manhattan Project, which develops the atomic bomb.");
    Film film6("Indiana Jones and the Dial of Destiny", "James Mangold", "Harrison Ford, Phoebe Waller-Bridge, Mads Mikkelsen", 154, "The New and Thrilling Adventures of Archaeologist Indiana Jones Around the World.");
    Film film7("Spider-Man: Across the Spider-Verse", "Joaquim Dos Santos, Kemp Powers, Justin K. Thompson", "Shameik Moore, Hailee Steinfeld, Brian Tyree Henry", 140, "Spider-Man from different dimensions unite to save the multiverse from a powerful threat.");
    Film film8("The Matrix", "The Wachowskis", "Keanu Reeves, Laurence Fishburne, Carrie-Anne Moss", 136, "A hacker discovers a simulated reality controlled by machines and joins a rebellion to free humanity.");

    // Creazione delle sale
    Hall hall1(1, 5, 7);
    Hall hall2(2, 6, 5);
    Hall hall3(3, 7, 6);
    Hall hall4(4, 10, 8);
    Hall hall5(5, 10, 10);
    Hall hall6(6, 10, 8);

    // Creazione dei posti
    mySet<const Seat *> vip1;
    unsigned int centerRow1 = hall1.getMaxRow() / 2 + 1;
    unsigned int startColumn1 = hall1.getMaxColumn() / 2;
    for (unsigned int column = startColumn1; column < startColumn1 + 3; ++column)
    {
        VipPriceSeat *v = new VipPriceSeat(centerRow1, column, {Beverages, Food, Footrest, Reclinig});
        vip1.push_back(v);
    }
    mySet<const Seat *> vip2;
    unsigned int centerRow2 = hall2.getMaxRow() / 2 + 1;
    unsigned int centerColumn2 = hall2.getMaxColumn() / 2 + 1;
    for (unsigned int column = centerColumn2 - 1; column <= centerColumn2 + 1; ++column)
    {
        VipPriceSeat *v = new VipPriceSeat(centerRow2, column, {Reclinig});
        vip2.push_back(v);
    }
    mySet<const Seat *> vip3;
    unsigned int centerRow3 = hall3.getMaxRow() / 2 + 1;
    unsigned int centerColumn3 = hall3.getMaxColumn() / 2;
    for (unsigned int column = centerColumn3 - 1; column <= centerColumn3 + 2; ++column)
    {
        VipPriceSeat *v = new VipPriceSeat(centerRow3, column, {Beverages,Food});
        vip3.push_back(v);
    }
    mySet<const Seat *> vip4;
    unsigned int centerRow4 = hall4.getMaxRow() / 2 + 1;
    unsigned int centerColumn4 = hall4.getMaxColumn() / 2;
    for (unsigned int column = centerColumn4 - 1; column <= centerColumn4 + 2; ++column)
    {
        VipPriceSeat *v = new VipPriceSeat(centerRow4, column, {Beverages, Footrest});
        vip4.push_back(v);
    }
    mySet<const Seat *> vip6(vip4);
    mySet<const Seat *> vip5(vip4);
    DiscountedPriceSeat discounted1(1, 1, 30);
    DiscountedPriceSeat discounted2(1, 2);
    DiscountedPriceSeat discounted3(hall2.getMaxRow(), hall2.getMaxColumn(), 25);
    DiscountedPriceSeat discounted4(hall2.getMaxRow(), hall2.getMaxColumn() - 1);
    DiscountedPriceSeat discounted5(hall4.getMaxRow(), hall4.getMaxColumn());
    DiscountedPriceSeat discounted6(hall4.getMaxRow(), hall4.getMaxColumn() - 1, 35);
    DiscountedPriceSeat discounted7(hall5.getMaxRow(), hall5.getMaxColumn());
    DiscountedPriceSeat discounted8(hall5.getMaxRow(), hall5.getMaxColumn() - 1);

    // Aggiunta dei posti alla sala
    hall1.replaceManySeats(vip1);
    hall1.replaceSeat(discounted1);
    hall1.replaceSeat(discounted2);
    hall2.replaceManySeats(vip2);
    hall2.replaceSeat(discounted1);
    hall2.replaceSeat(discounted3);
    hall2.replaceSeat(discounted4);
    hall3.replaceManySeats(vip3);
    hall4.replaceSeat(discounted5);
    hall4.replaceSeat(discounted6);
    hall4.replaceManySeats(vip4);
    hall5.replaceManySeats(vip5);
    hall5.replaceSeat(discounted7);
    hall5.replaceSeat(discounted8);
    hall6.replaceManySeats(vip6);
    hall6.replaceSeat(discounted8);

    hall1.replaceSeat(UnavailableSeat(1, 1));
    hall6.replaceSeat(UnavailableSeat(hall6.getMaxRow(), hall6.getMaxRow()));
    hall5.replaceSeat(UnavailableSeat(hall5.getMaxRow(), 1));
    hall2.replaceSeat(UnavailableSeat(1, hall2.getMaxColumn()));

    // Creazione delle date
    tm myDate1 = Programming::createTmFromString("Wednesday, 21/06/2023 12:30:00", "%A, %d/%m/%Y %H:%M:%S");
    tm myDate2 = Programming::createTmFromString("Wednesday, 21/06/2023 18:30:00", "%A, %d/%m/%Y %H:%M:%S");
    tm myDate3 = Programming::createTmFromString("Wednesday, 21/06/2023 20:20:00", "%A, %d/%m/%Y %H:%M:%S");
    tm myDate4 = Programming::createTmFromString("Wednesday, 21/06/2023 21:30:00", "%A, %d/%m/%Y %H:%M:%S");
    tm myDate5 = Programming::createTmFromString("Thursday, 22/06/2023 15:45:00", "%A, %d/%m/%Y %H:%M:%S");
    tm myDate6 = Programming::createTmFromString("Thursday, 22/06/2023 18:15:00", "%A, %d/%m/%Y %H:%M:%S");
    tm myDate7 = Programming::createTmFromString("Thursday, 22/06/2023 21:30:00", "%A, %d/%m/%Y %H:%M:%S");
    tm myDate8 = Programming::createTmFromString("Friday, 23/06/2023 19:00:00", "%A, %d/%m/%Y %H:%M:%S");
    tm myDate9 = Programming::createTmFromString("Friday, 23/06/2023 21:30:00", "%A, %d/%m/%Y %H:%M:%S");
    tm myDate10 = Programming::createTmFromString("Saturday, 24/06/2023 17:30:00", "%A, %d/%m/%Y %H:%M:%S");
    tm myDate11 = Programming::createTmFromString("Saturday, 24/06/2023 20:20:00", "%A, %d/%m/%Y %H:%M:%S");
    tm myDate12 = Programming::createTmFromString("Saturday, 24/06/2023 21:30:00", "%A, %d/%m/%Y %H:%M:%S");

    // Aggiunta delle proiezioni
    p.addSchedule(film3, myDate2, hall6);
    p.addSchedule(film3, myDate3, hall3);
    p.addSchedule(film5, myDate2, hall4);
    p.addSchedule(film4, myDate2, hall1);
    p.addSchedule(film7, myDate1, hall5);
    p.addSchedule(film1, myDate2, hall2);
    p.addSchedule(film7, myDate2, hall5);
    p.addSchedule(film4, myDate4, hall1);
    p.addSchedule(film1, myDate4, hall2);
    p.addSchedule(film3, myDate4, hall6);
    p.addSchedule(film5, myDate4, hall4);
    p.addSchedule(film7, myDate4, hall5);

    p.addSchedule(film7, myDate5, hall5);
    p.addSchedule(film6, myDate5, hall1);
    p.addSchedule(film6, myDate6, hall1);
    p.addSchedule(film3, myDate6, hall3);
    p.addSchedule(film5, myDate6, hall4);
    p.addSchedule(film2, myDate6, hall2);
    p.addSchedule(film7, myDate6, hall5);
    p.addSchedule(film6, myDate7, hall1);
    p.addSchedule(film2, myDate7, hall2);
    p.addSchedule(film3, myDate7, hall3);
    p.addSchedule(film5, myDate7, hall4);
    p.addSchedule(film7, myDate7, hall5);

    p.addSchedule(film3, myDate8, hall6);
    p.addSchedule(film5, myDate8, hall4);
    p.addSchedule(film7, myDate8, hall2);
    p.addSchedule(film6, myDate8, hall3);
    p.addSchedule(film3, myDate9, hall6);
    p.addSchedule(film5, myDate9, hall4);
    p.addSchedule(film6, myDate9, hall3);
    p.addSchedule(film4, myDate9, hall5);

    p.addSchedule(film3, myDate10, hall5);
    p.addSchedule(film5, myDate10, hall1);
    p.addSchedule(film8, myDate10, hall4);
    p.addSchedule(film6, myDate10, hall6);
    p.addSchedule(film7, myDate10, hall3);
    p.addSchedule(film3, myDate11, hall2);
    p.addSchedule(film5, myDate11, hall1);
    p.addSchedule(film6, myDate11, hall6);
    p.addSchedule(film3, myDate12, hall5);
    p.addSchedule(film5, myDate12, hall1);
    p.addSchedule(film6, myDate12, hall6);
    p.addSchedule(film7, myDate12, hall3);
    p.addSchedule(film8, myDate12, hall4);

    QApplication app(argc, argv);
    MainWindow mainWindow(p);
    mainWindow.resize(1024, 976);
    mainWindow.show();
    return app.exec();
}
