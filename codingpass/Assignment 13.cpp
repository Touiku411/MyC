#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
using namespace std;

struct Date
{
    int year;
    int month;
    int day;
};

struct Reservation
{
    char flightNo[8]; // flight number
    char id[12];      // ID number
    char name[8];     // name
    char mobile[12];  // mobile phone number
    char date[12];    // departure date
    int tickets[8];
    // tickets[ 0 ]: not used
    // tickets[ 1 ]: number of full fare tickets
    // tickets[ 2 ]: number of child tickets
    // tickets[ 3 ]: number of infant tickets
    // tickets[ 4 ]: number of senior citizen tickets
    // tickets[ 5 ]: number of impaired tickets
    // tickets[ 6 ]: number of impaired companion tickets
    // tickets[ 7 ]: number of military tickets
};

struct Flight
{
    char flightNo[8];      // flight number
    char aircraft[8];      // aircraft model
    int departureAirport;    // departure airport code
    int arrivalAirport;      // arrival airport code
    char departureTime[8]; // departure time
    char arrivalTime[8];   // arrival time
    int dayWeek[7];        // the value of dayWeek[ i ] is 0 or 1
    // dayWeek[ 0 ] == 1 if and only if the flight flies on Sunday
    // dayWeek[ 1 ] == 1 if and only if the flight flies on Monday
    // dayWeek[ 2 ] == 1 if and only if the flight flies on Tuesday
    // dayWeek[ 3 ] == 1 if and only if the flight flies on Wednesday
    // dayWeek[ 4 ] == 1 if and only if the flight flies on Thursday
    // dayWeek[ 5 ] == 1 if and only if the flight flies on Friday
    // dayWeek[ 6 ] == 1 if and only if the flight flies on Saturday
};

struct FlightSeats
{
    char date[12];      // date
    char flightNo[8];   // flight number
    int departureAirport; // departure airport code
    int arrivalAirport;   // arrival airport code
    int availableSeats;   // the number of available seats
};

const char airportName[12][12] = { "", "Taipei",    "Taichung", "Chiayi",  "Tainan",
                                         "Kaohsiung", "Hualien", "Taitung",
                                         "Penghu",    "Kinmen",   "Beigan",  "Nangan" };

// row 0 and column 0 are not used,
// fullFare[ i ][ j ] is the full fare from airport i to airport j
const int fullFare[12][12] = {
   { 0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
   { 0,    0,    0,    0,    0,    0, 1781, 2460, 2296, 2618, 2197, 2197 },
   { 0,    0,    0,    0,    0,    0,    0,    0, 1769, 2236,    0, 2686 },
   { 0,    0,    0,    0,    0,    0,    0,    0, 1721, 2217,    0,    0 },
   { 0,    0,    0,    0,    0,    0,    0,    0, 1697, 2231,    0,    0 },
   { 0,    0,    0,    0,    0,    0,    0,    0, 1876, 2393,    0,    0 },
   { 0, 1781,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
   { 0, 2460,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
   { 0, 2296, 1769, 1721, 1697, 1876,    0,    0,    0, 1768,    0,    0 },
   { 0, 2618, 2236, 2217, 2231, 2393,    0,    0, 1768,    0,    0,    0 },
   { 0, 2197,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
   { 0, 2197, 2686,    0,    0,    0,    0,    0,    0,    0,    0,    0 } };

const int discount[8] = { 0, 100, 75, 0, 50, 50, 50, 95 };
// discount[ 0 ]: not used
// discount[ 1 ]: Full Fare Ticket (���B��)
// discount[ 2 ]: Child Ticket (�ൣ��):                 25% off of the full fare
// discount[ 3 ]: Infant Ticket (���಼):                Free of charge
// discount[ 4 ]: Senior Citizen Ticket (�q�Ѳ�):        50% off of the full fare
// discount[ 5 ]: Impaired Ticket (�R�߲�):              50% off of the full fare
// discount[ 6 ]: Impaired Companion Ticket (�R�߳��P��): 50% off of the full fare
// discount[ 7 ]: Military Ticket (�x�H��):               5% off of the full fare

const int maxNumReservations = 1000;

int enterChoice();

// perform booking
void booking();

// choose arrival airport by input its code, and assign the code to arrivalAirport
void chooseArrivalAirport(int departureAirport, int& arrivalAirport);

// input the departure date
void inputDepartureDate(char date[], int& departureDayWeek);

// return the number of days between currentDate and departureDate
int difference(Date departureDate, Date currentDate);

bool leapYear(int year);

// load all flights from Flight Schedule.dat and put them into the array flights
void loadFlightSchedules(Flight flights[], int& numFlights);

// load all flights from departureAirport to arrivalAirport,
// and put them into the array flights
void loadFlightSchedules(Flight flights[], int& numFlights,
    int departureAirport, int arrivalAirport, int departureDayWeek);

// load all flightSeats from departureAirport to arrivalAirport on departureDate,
// and put them into the array flightSeats
void loadFlightSeats(FlightSeats flightSeats[], int& numFlightSeats, char departureDate[],
    int departureAirport, int arrivalAirport);

// display all flights from departureAirport to arrivalAirport
void displayFlights(const Flight flights[], int numFlights,
    FlightSeats flightSeats[], int& numFlightSeats,
    int departureAirport, int arrivalAirport, char date[]);

// choose a flight by input its number,
// and assign the number to reservation.flightNo
void chooseFlight(Reservation& reservation, const Flight flights[], int numFlights);

// input the number of tickets for each ticket type,
// and assign them to reservation.tickets
void inputNumTickets(Reservation& reservation, FlightSeats flightSeats[], int& numFlightSeats);

// during booking and refund application,
// the corresponding availableSeats in Flight Seats.dat should be modified
void modifyFlightSeatsFile(Reservation& reservation, int totalNumTickets);

void displayReservation(const Reservation reservation,
    const Flight flights[], int numFlights);

// append reservation to the end of Reservations.dat
void saveReservation(const Reservation reservation);

// perform booking inquiry
bool bookingInquiry(const char id[]);

// perform refund application
void refundApplication();

// load all reservations from Reservations.dat and put them to the array reservations
void loadReservations(Reservation reservations[], int& numReservations);

int main()
{
    cout << "Welcome to UNI Air Domestic Flights Booking System\n";
    char id[12];
    int choice;

    while ((choice = enterChoice()) != 4)
    {
        switch (choice)
        {
        case 1:
            booking(); // perform booking
            break;
        case 2:
            cout << "\nEnter ID number: ";
            cin >> id;
            bookingInquiry(id); // perform booking inquiry
            break;
        case 3:
            refundApplication(); // perform refund application
            break;

        default:
            cout << "\nInput error!\n";
            break;
        }
    }

    cout << endl;
    system("pause");
}

int enterChoice()
{
    cout << "\nInput your choice:\n"
        << "1. Booking\n"
        << "2. Booking enquiry\n"
        << "3. Refund application\n"
        << "4. End\n? ";

    int menuChoice;
    cin >> menuChoice;
    return menuChoice;
}

// perform booking
void booking()
{
    // choose departure airport by input its code,
    // and assign the code to departureAirport
    int departureAirport;
    do {
        cout << "\nDeparture airport:\n";
        for (int i = 1; i <= 11; i++)
            cout << setw(2) << i << ". " << airportName[i] << endl;
        cout << "? ";

        cin >> departureAirport;
    } while (departureAirport < 1 || departureAirport > 11);

    int arrivalAirport;
    // choose arrival airport by input its code, and assign the code to arrivalAirport
    chooseArrivalAirport(departureAirport, arrivalAirport);

    Reservation reservation = { "", "", "", "", "", 0, 0, 0, 0, 0, 0, 0, 0 };

    int departureDayWeek; // departureDayWeek == 0 if departure date is Sunday
    // departureDayWeek == 1 if departure date is Monday
    // departureDayWeek == 2 if departure date is Tuesday
    // departureDayWeek == 3 if departure date is Wednesday
    // departureDayWeek == 4 if departure date is Thursday
    // departureDayWeek == 5 if departure date is Friday
    // departureDayWeek == 6 if departure date is Saturday

    inputDepartureDate(reservation.date, departureDayWeek);

    Flight flights[20];
    int numFlights = 0;

    // load all flights from departureAirport to arrivalAirport,
    // and put them into the array flights
    loadFlightSchedules(flights, numFlights, departureAirport, arrivalAirport,
        departureDayWeek);

    FlightSeats flightSeats[20];
    int numFlightSeats = 0;

    loadFlightSeats(flightSeats, numFlightSeats, reservation.date,
        departureAirport, arrivalAirport);

    // display all flights from departureAirport to arrivalAirport
    displayFlights(flights, numFlights, flightSeats, numFlightSeats,
        departureAirport, arrivalAirport, reservation.date);

// choose a flight by input its number, and assign the number to reservation.flightNo
chooseFlight(reservation, flights, numFlights);

// input the number of tickets for each ticket type,
// and assign them to reservation.tickets
inputNumTickets(reservation, flightSeats, numFlightSeats);

int totalNumTickets = 0;
for (int i = 1; i < 8; i++)
    totalNumTickets += reservation.tickets[i];

if (totalNumTickets > 0)
modifyFlightSeatsFile(reservation, totalNumTickets);
else
{
    cout << "Your booking could not be completed!\n";
    return;
}

displayReservation(reservation, flights, numFlights);

cout << "\nID number: ";
cin >> reservation.id;
cout << "\nName: ";
cin >> reservation.name;
cout << "\nMobile: ";
cin >> reservation.mobile;

// append reservation to the end of Reservations.dat
saveReservation(reservation);

cout << "\nBooking completed!\n";
}

// choose arrival airport by input its code, and assign the code to arrivalAirport
void chooseArrivalAirport(int departureAirport, int& arrivalAirport)
{
    int Array[50];
    int ArraySize = 0;
    for (int i = 1; i <= 12; ++i) {
        if (fullFare[departureAirport][i] != 0) {
            ArraySize++;
            Array[ArraySize] = i;
        }
    }
    int choice;
    bool isValid = false;
    do {
        cout << "\nArrival airport:\n";
        for (int i = 1; i <= ArraySize; ++i) {
            cout << setw(2) << right << Array[i] << ". " << airportName[Array[i]] << endl;
        }
        cout << "? ";
        cin >> choice;
        for (int i = 1; i <= ArraySize; ++i) {
            if (Array[i] == choice) {
                isValid = true;
                break;
            }
        }
    } while (!isValid);
    arrivalAirport = choice;
}

void inputDepartureDate(char date[], int& departureDayWeek)
{
    tm structuredTime;
    time_t rawTime = time(nullptr);
    localtime_s(&structuredTime, &rawTime);

    int year = structuredTime.tm_year + 1900;
    int month = structuredTime.tm_mon + 1;
    int day = structuredTime.tm_mday;

    int selectDate;
    Date Dates[7];
    Date d = { year,month,day };
    do {
        d.year = year; d.month = month; d.day = day;
        cout << "\nDeparture Date (Month):\n";
        for (int i = 1; i <= 6; ++i) {
            Dates[i] = d;
            cout << i << ". " << d.year << "-" << d.month << endl;
            if (d.month == 12) {
                d.year++;
                d.month = 1;
            }
            else {
                d.month++;
            }
        }
        cout << "? ";
        cin >> selectDate;
    } while (selectDate < 1 || selectDate > 6);
    cout << endl;
    int choiceDay;
    int diff;
    Date curD = { year,month,day };
    int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int minDay = 0;
    int maxDay = 0;
    do {
        if (leapYear(Dates[selectDate].year) && Dates[selectDate].month == 2) {
            daysInMonth[2] = 29;
        }
        else {
            daysInMonth[2] = 28;
        }
        maxDay = daysInMonth[Dates[selectDate].month];
        if(Dates[selectDate].year == curD.year && Dates[selectDate].month == curD.month){
            minDay = curD.day;
        }
        else {
            minDay = 1;
        }
        cout << "\nDay (" << minDay << " ~ " << maxDay << "): ";
        cin >> choiceDay;
        Dates[selectDate].day = choiceDay;
        diff = difference(Dates[selectDate], curD);
    } while (choiceDay < minDay || choiceDay > maxDay || diff < 0);
    //snprintf
    sprintf_s(date, 12, "%d/%02d/%02d", Dates[selectDate].year, Dates[selectDate].month, choiceDay);

    tm time_in = { 0 };
    time_in.tm_year = Dates[selectDate].year - 1900;
    time_in.tm_mon = Dates[selectDate].month - 1;
    time_in.tm_mday = choiceDay;
    mktime(&time_in);
    departureDayWeek = time_in.tm_wday;
}

int difference(Date departureDate, Date currentDate)
{
     tm date1 = { 0 };
     tm date2 = { 0 };
     date1.tm_year = departureDate.year - 1900;
     date1.tm_mon = departureDate.month - 1;
     date1.tm_mday = departureDate.day;
     date2.tm_year = currentDate.year - 1900;
     date2.tm_mon = currentDate.month - 1;
     date2.tm_mday = currentDate.day;
     time_t d1 = mktime(&date1);
     time_t d2 = mktime(&date2);
     double diff = difftime(d1, d2);
     return static_cast<int>(diff / (24 * 60 * 60));

    // int totalDep = 0;
    // int totalCur = 0;
    // const int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    // for (int i = 1; i < departureDate.year; ++i) {
    //     totalDep += (leapYear(i)) ? 366 : 365;
    // }
    // for (int i = 1; i < departureDate.month; ++i) {
    //     if (i == 2 && leapYear(departureDate.year))
    //         totalDep += 29;
    //     else 
    //         totalDep += daysInMonth[i];
    // }
    // totalDep += departureDate.day;

    // for (int i = 1; i < currentDate.year; ++i) {
    //     totalCur += (leapYear(i)) ? 366 : 365;
    // }
    // for (int i = 1; i < currentDate.month; ++i) {
    //     if (i == 2 && leapYear(currentDate.year))
    //         totalCur += 29;
    //     else
    //         totalCur += daysInMonth[i];
    // }
    // totalCur += currentDate.day;

    // return totalDep - totalCur;
}

bool leapYear(int year)
{
    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

// load all flights from Flight Schedule.dat and put them into the array flights
void loadFlightSchedules(Flight flights[], int& numFlights)
{
    ifstream inFile("Flight Schedule.dat", ios::binary);
    if (!inFile) {
        cout << "\ncan not read Flight Schedule.dat!\n";
        return;
    }
    numFlights = 0;
    Flight f;
    while (inFile.read(reinterpret_cast<char*>(&f), sizeof(Flight))) {
        numFlights++;
        flights[numFlights] = f;
    }
    inFile.close();
}

// load all flights from departureAirport to arrivalAirport,
// and put them into the array flights
void loadFlightSchedules(Flight flights[], int& numFlights,
    int departureAirport, int arrivalAirport, int departureDayWeek)
{
    Flight flight[200];
    int flightSize = 0;
    loadFlightSchedules(flight, flightSize);
    for (int i = 1; i <= flightSize; ++i) {
        if (flight[i].departureAirport == departureAirport &&
            flight[i].arrivalAirport == arrivalAirport &&
            flight[i].dayWeek[departureDayWeek] != 0) {
            numFlights++;
            flights[numFlights] = flight[i];
        }
    }

}

void loadFlightSeats(FlightSeats flightSeats[], int& numFlightSeats, char departureDate[],
    int departureAirport, int arrivalAirport)
{
    ifstream inFile("Flight Seats.dat", ios::binary);
    if (!inFile) {
        cout << "\ncan not open Flight Seats.dat!\n";
        return;
    }
    FlightSeats fs;
    while (inFile.read(reinterpret_cast<char*>(&fs), sizeof(FlightSeats))) {
        if (fs.departureAirport == departureAirport &&
            fs.arrivalAirport == arrivalAirport &&
            strcmp(fs.date, departureDate) == 0) {
            numFlightSeats++;
            flightSeats[numFlightSeats] = fs;
        }
    }
    inFile.close();
}

// display all flights from departureAirport to arrivalAirport
void displayFlights(const Flight flights[], int numFlights,
    FlightSeats flightSeats[], int& numFlightSeats,
    int departureAirport, int arrivalAirport, char date[])
{
    cout << airportName[departureAirport] << " to " << airportName[arrivalAirport]
        << " / Depart date: " << date << ".\n\n";
        cout << "Flight   Departure   Arrival   Fare   No. Available Seats\n";

        for (int i = 1; i <= numFlights; i++)
            if (flightSeats[i].availableSeats > 0)
                cout << setw(6) << flights[i].flightNo
                << setw(12) << flights[i].departureTime
                << setw(10) << flights[i].arrivalTime
                << setw(7) << fullFare[departureAirport][arrivalAirport]
            << setw(22) << flightSeats[i].availableSeats << endl;
}

// choose a flight by input its number, and assign the number to reservation.flightNo
void chooseFlight(Reservation& reservation, const Flight flights[], int numFlights)
{
    char selectfNo[8];
    bool isValid = false;
    do {
        cout << "\nFlight number: ";
        cin >> selectfNo;
        for (int i = 1; i <= numFlights; ++i) {
            if (strcmp(flights[i].flightNo, selectfNo) == 0) {
                isValid = true;
                break;
            }
        }
    } while (!isValid);
    strcpy_s(reservation.flightNo, 8, selectfNo);
}

// input the number of tickets for each ticket type, and assign them to reservation.tickets
void inputNumTickets(Reservation& reservation, FlightSeats flightSeats[], int& numFlightSeats)
{
    int i;
    for (i = 1; i <= numFlightSeats; i++)
        if (strcmp(reservation.flightNo, flightSeats[i].flightNo) == 0)
            break;

    int numAvailableSeats = flightSeats[i].availableSeats;
    int maxNumTickets = (numAvailableSeats < 4) ? numAvailableSeats : 4;

    do {
        cout << "\nNumber of infant tickets (0 ~ " << maxNumTickets << "): ";
        cin >> reservation.tickets[3];
    } while (reservation.tickets[3] < 0 || reservation.tickets[3] > maxNumTickets);

    int numTickets = 0;
    int numAdults = 0;
    do
    {
        numTickets = 0;

        cout << "\nNumber of full fare tickets (0 ~ " << maxNumTickets << "): ";
        cin >> reservation.tickets[1];
        numTickets += reservation.tickets[1];

        cout << "\nNumber of child tickets (0 ~ " << maxNumTickets << "): ";
        cin >> reservation.tickets[2];
        numTickets += reservation.tickets[2];

        cout << "\nNumber of senior citizen tickets (0 ~ " << maxNumTickets << "): ";
        cin >> reservation.tickets[4];
        numTickets += reservation.tickets[4];

        cout << "\nNumber of impaired tickets (0 ~ " << maxNumTickets << "): ";
        cin >> reservation.tickets[5];
        numTickets += reservation.tickets[5];

        cout << "\nNumber of impaired companion tickets (0 ~ " << maxNumTickets << "): ";
        cin >> reservation.tickets[6];
        numTickets += reservation.tickets[6];

        cout << "\nNumber of military tickets (0 ~ " << maxNumTickets << "): ";
        cin >> reservation.tickets[7];
        numTickets += reservation.tickets[7];

        numAdults = reservation.tickets[1] + reservation.tickets[4] +
            reservation.tickets[5] + reservation.tickets[6] +
            reservation.tickets[7];

        if (numTickets > maxNumTickets)
            cout << "\nYou can books a maximum of " << maxNumTickets
            << " passengers ( including children ).\n";
        else if (numAdults < reservation.tickets[3])
            cout << "\nEach infant must always be accompanied by at least one adult.\n";
    } while (numTickets > maxNumTickets || numAdults < reservation.tickets[3]);

    cout << endl;
}

void modifyFlightSeatsFile(Reservation& reservation, int totalNumTickets)
{
    fstream File("Flight Seats.dat", ios::binary | ios::in | ios::out);
    if (!File) {
        cout << "\ncan not modify Flight Seats.dat!\n";
        return;
    }
    FlightSeats fs;
    while (File.read(reinterpret_cast<char*>(&fs), sizeof(FlightSeats))) {
        if (strcmp(fs.date, reservation.date) == 0 &&
            strcmp(fs.flightNo, reservation.flightNo) == 0) {
            File.seekp(-static_cast<int>(sizeof(FlightSeats)), ios::cur);
            fs.availableSeats -= totalNumTickets;
            File.write(reinterpret_cast<char*>(&fs), sizeof(FlightSeats));
            break;
        }
    }
    File.close();
}

void displayReservation(const Reservation reservation,
    const Flight flights[], int numFlights)
{
    int k;
    for (k = 1; k <= numFlights; k++)
        if (strcmp(reservation.flightNo, flights[k].flightNo) == 0)
            break;

    cout << "Ticket information:\n\n";
    cout << "Date: " << reservation.date << endl;
    cout << "Flight: B7-" << reservation.flightNo << endl << endl;

    int departureAirport = flights[k].departureAirport;
    int arrivalAirport = flights[k].arrivalAirport;

    cout << setw(9) << right << airportName[departureAirport] << " -> "
        << setw(9) << left << airportName[arrivalAirport] << endl;

    cout << setw(9) << right << flights[k].departureTime << "    ";
    cout << setw(9) << left << flights[k].arrivalTime << endl << endl;

    char ticketType[8][24] = { "", "Full Fare", "Child Fare", "Infant Fare",
                                       "Senior Citizen Fare",     "Impaired Fare",
                                       "Impaired Companion Fare", "Military Fare" };

    int total = 0;
    int fare;
    for (int i = 1; i <= 7; i++)
        if (reservation.tickets[i] > 0)
        {
            fare = fullFare[departureAirport][arrivalAirport] * discount[i] / 100;
            total += (fare * reservation.tickets[i]);
            cout << right << setw(23) << ticketType[i] << "  TWD "
                << setw(4) << fare << " x " << reservation.tickets[i] << endl;
        }

    cout << "\nTotal: " << total << endl;
}

// append reservation to the end of Reservations.dat
void saveReservation(const Reservation reservation)
{
    ofstream outFile("Reservations.dat", ios::binary | ios::app);
    if (!outFile) {
        cout << "\ncan not save Reservations.dat!\n";
        return;
    }
    outFile.write(reinterpret_cast<const char*>(&reservation), sizeof(Reservation));
}

// perform booking inquiry
bool bookingInquiry(const char id[])
{
    bool found = false;

    Reservation res[1000];
    int resSize = 0;
    Flight flight[200];
    int flightSize = 0;
    loadFlightSchedules(flight, flightSize);
    loadReservations(res, resSize);
    int cnt = 1;
    for (int i = 1; i <= resSize; ++i) {
        if (strcmp(res[i].id, id) == 0) {
            cout << endl << cnt++ << ". ";
            displayReservation(res[i], flight, flightSize);
            found = true;
        }
    }
    if (!found) {
        cout << "\nNo reservations!\n";
    }
    return found;
}

// perform refund application
void refundApplication()
{
    char id[12];

    cout << "\nEnter ID number: ";
    cin >> id;

    if (!bookingInquiry(id))
        return;

    int choice;
    cout << "\nEnter your choice: ";
    cin >> choice;

    Reservation reservations[maxNumReservations];
    int numReservations;
    loadReservations(reservations, numReservations);

    int realidx = -1;
    int idx = 0;
    for (int i = 1; i <= numReservations; ++i) {
        if (strcmp(reservations[i].id, id) == 0) {
            idx++;
            if (idx == choice) {
                realidx = i;
                break;
            }
        }
    }
    int numTotalTicket = 0;
    if (realidx == -1) {
        cout << "\nreservation not found\n";
        return;
    }
    for (int i = 1; i <= 7; ++i) {
        numTotalTicket += reservations[realidx].tickets[i];
    }
    modifyFlightSeatsFile(reservations[realidx], -numTotalTicket);

    ofstream outFile("Reservations.dat", ios::binary);
    for (int i = 1; i <= numReservations; ++i) {
        if (i != realidx) {
            outFile.write(reinterpret_cast<char*>(&reservations[i]), sizeof(Reservation));
        }
    }
    outFile.close();

    cout << "\nThe seleted booking has been deleted.\n";
}

// load all reservations from Reservations.dat and put them to the array reservations
void loadReservations(Reservation reservations[], int& numReservations)
{
    ifstream inFile("Reservations.dat", ios::binary);
    if (!inFile) {
        cout << "\nCan not load Reservations.dat!\n";
        return;
    }
    numReservations = 0;
    Reservation res;
    while (inFile.read(reinterpret_cast<char*>(&res), sizeof(Reservation))) {
        numReservations++;
        reservations[numReservations] = res;
    }
    inFile.close();
}
