#include <iostream>

#include<windows.h>

#include<stdio.h>

#include<mysql.h>

#include<string>

#include<sstream>

#include<conio.h>

#include<string.h>

#include<fstream>

#include<cctype>

#include<iomanip>

#include<stdlib.h>

#include<cstdlib>

#include <ctime>

#include<time.h>

#include <bits/stdc++.h>

#include<regex>

#include <cstdio>

#include <dos.h>

#include <dir.h>

#include <unistd.h>

#include <stdlib.h>

using namespace std;

const char * hostname = "localhost";
const char * username = "root";
const char * password = "";
const char * database = "banking_project";
unsigned int port = 3306;
const char * unixsocket = NULL;
unsigned long clientflag = 0;
MYSQL * connectdatabase() {
  MYSQL * conn;
  conn = mysql_init(0);
  conn = mysql_real_connect(conn, hostname, username, password, database, port, unixsocket, clientflag);
  if (!conn)

  {
    cout << "CONNECTION ERROR" << endl;
    return conn;
  }
}

class bank {

  public:

    MYSQL * conn = connectdatabase();



  /*RANDOM CHARACTER*/
  string gen_random(const int len) {

    string tmp_s;
    static
    const char alphanum[] = "ABCDEFGHIJKLMNOPQRSTU"
    "abcdefghijklmnopqrstuvwxyz";

    srand((unsigned) time(NULL) * getpid());

    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i)
      tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];

    return tmp_s;

  }

  /* RANDOM NUMBER*/

  string gen_random_num(const int len) {

    string tmp_s;
    static
    const char alphanum[] = "123456789";

    srand((unsigned) time(NULL) * getpid());

    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i)
      tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];

    return tmp_s;

  }

  /* BANK MANAGEMENT FUNCTIONS */
  string menu(MYSQL * conn);
  string bankmangement(MYSQL * conn);
  string insertrecord(MYSQL * conn);
  string displayrecords(MYSQL * conn);
  string atmmangement(MYSQL * conn);
  string deleterecord(MYSQL * conn);
  string updaterecord(MYSQL * conn);
  string showspecificrecord(MYSQL * conn);
  string depositamt(MYSQL * conn);
  string withdrawamt(MYSQL * conn);
  string transfer_amt(MYSQL * conn);
  string update_name(MYSQL * conn);
  string update_adhar(MYSQL * conn);
  string update_mobno(MYSQL * conn);
  string update_email(MYSQL * conn);
  string update_address(MYSQL * conn);
  string trans_hist(MYSQL * conn);
  string trans_hist_download(MYSQL * conn);

  /* END */

  /* ATM MANAGEMENT FUNCTION*/
  string checkbalance(MYSQL * conn);
  string withdrawamt_atm(MYSQL * conn);
  string changepin_atm(MYSQL * conn);
  string forgotpin_atm(MYSQL * conn);
  string depositamt_atm(MYSQL * conn);
  /* END ATM FUNVTIONS */

  /*validations functions */
  bool Email(string email) {
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email, pattern);
  }

  bool number(string number) {
    //const regex pattern("[-+]?([0-9]*\.[0-9]+|[0-9]+)");
    const regex pattern("^[0-9]{4}$");
    return regex_match(number, pattern);
  }

  bool number_only(string number_only) {
    const regex pattern("[-+]?([0-9]*\.[0-9]+|[0-9]+)");
    //const regex pattern("^[0-9]{12}$");
    return regex_match(number_only, pattern);
  }

  bool number_onl(string number_onl) {
    regex pattern("^[0-9]$");
    //const regex pattern("^[0-9]{12}$");
    return regex_match(number_onl, pattern);
  }

  bool number_pin(string number_onl) {
    regex pattern("^[0-9]{4}$");
    //const regex pattern("^[0-9]{12}$");
    return regex_match(number_onl, pattern);
  }

  bool number_ten(string number_ten) {
    //const regex pattern("[-+]?([0-9]*\.[0-9]+|[0-9]+)");
    const regex pattern("^[0-9]{10}$");
    return regex_match(number_ten, pattern);
  }

  bool character(string character) {
    //const regex pattern("[-+]?([0-9]*\.[0-9]+|[0-9]+)");
    const regex pattern("^[a-z A-Z]+$");
    return regex_match(character, pattern);
  }

  bool acctype(string acctype) {
    //const regex pattern("[-+]?([0-9]*\.[0-9]+|[0-9]+)");
    const regex pattern("^[CS]+$");
    return regex_match(acctype, pattern);
  }

  /* validations end */


};

string bank::menu(MYSQL * conn) {
  if (conn) {
    p: system("cls");
    MYSQL_ROW row;
    MYSQL_RES * res;
    string email,
    password,
    pin,
    name;
    stringstream ssa;
    string query;
    const char * q;
    int count;
    my_ulonglong x;
    string choi;
    system("Color 0F");
    cout << "\n\n 1.BANK MANAGEMENT";
    cout << "\n\n 2.ATM MANAGEMENT";
    cout << "\n\n 3.EXIT ";
    cout << "\n\n ENTER YOUR CHOICE: ";
    cin >> choi;
    if (number_onl(choi)) {

      goto sd;
    } else {
      system("Color 0C");
      cout << "\n\nINVALID INPUT PLEASE TRY AGAIN SELECT [1 to 3] BETWEEN  ";
      PlaySound(TEXT("error.wav"), NULL, SND_SYNC);

      getch();
      goto p;

    }

    sd: int num = stoi(choi);

    switch (num) {

    case 1:
      bankmangement(conn);
      /*
          cout<<"\n\nENTER EMAIL: ";
          cin>>email;
          ssa<< "select * from appoint_bank_employee where email = '"+email+"' ";
          query = ssa.str();
           q= query.c_str();
          mysql_query(conn , q);
          res = mysql_store_result(conn);
          count = mysql_num_fields(res);
          x = mysql_num_rows(res);

          if(x>0)
          {
              while(row = mysql_fetch_row(res))
              {
                   cout<<"\n\nENTER Pin: ";
                      cin>>pin;
                  if(pin == row[2] )
                  {

                     cout<<"\n\nENTER Password: ";
                      cin>>password;
                      if(password == row[3]){
                          bankmangement(conn);
                      }else{
                          cout<<"\nPASSWORD IS INCORRECT";
                      }
                  }else{
                      cout<<"\n PIN IS INCORRECT";

                  }

              }


          }


          else{
                  cout<<"\n\n INVALID EMAIL ID ";
          }
      */

      break;

    case 2:
      atmmangement(conn);
      break;

    case 3:
      exit(0);

    default:
      cout << "\nINVALID INPUT PLEASE TRY AGAIN SELECT [1 to 3] BETWEEN";
      system("Color 0C");
      PlaySound(TEXT("error.wav"), NULL, SND_SYNC);

    }

    getch();
    goto p;
  }
  else {
    cout << "connection failed please try again.......";
  }
}

string bank::bankmangement(MYSQL * conn) {
  if (conn) {
    p: string choice;
    system("cls");
    system("Color 0F");
    cout << "\n\n 1. INSERT RECORD";
    cout << "\n\n 2. SHOW ALL RECORD ";
    cout << "\n\n 3. DELETE RECORD ";
    cout << "\n\n 4. UPDATE RECORD ";
    cout << "\n\n 5. SHOW SPECIFIC RECORD ";
    cout << "\n\n 6. DEPOSITE AMOUNT ";
    cout << "\n\n 7. WITHDRAW AMOUNT ";
    cout << "\n\n 8. TRANSFER MONEY ";
    cout << "\n\n 9. TRANSACATION HISTORY ";
    cout << "\n\n 10. TRANSACATION HISTORY DOWNLOAD";
    cout << "\n\n 11. goback ";

    cout << "\n\nENTER YOUR CHOICE: ";
    cin >> choice;

    if (number_only(choice)) {

      goto sd;
    } else {
      system("Color 0C");
      cout << "\n\nINVALID INPUT PLEASE TRY AGAIN SELECT [1 to 8] BETWEEN ";
      PlaySound(TEXT("error.wav"), NULL, SND_SYNC);

      getch();
      goto p;

    }
    sd: int num = stoi(choice);
    switch (num) {
    case 1:
      insertrecord(conn);
      break;

    case 2:
      displayrecords(conn);
      break;

    case 3:
      deleterecord(conn);
      break;

    case 4:
      updaterecord(conn);
      break;

    case 5:
      showspecificrecord(conn);
      break;

    case 6:
      depositamt(conn);
      break;

    case 7:
      withdrawamt(conn);
      break;

    case 8:
      transfer_amt(conn);
      break;

    case 9:
      trans_hist(conn);
      break;

    case 10:
      trans_hist_download(conn);
      break;

    case 11:
      menu(conn);
      break;

    default:
      cout << "\nINVALID INPUT PLEASE TRY AGAIN SELECT [1 to 8] BETWEEN";
      system("Color 0C");
      PlaySound(TEXT("error.wav"), NULL, SND_SYNC);

      break;

    }

    getch();
    goto p;

  }
  else {
    cout << "CONNECTION FAILED";
  }
}

string bank::insertrecord(MYSQL * conn) {
  on: MYSQL_ROW row;
  MYSQL_RES * res;
  MYSQL_RES * resss;

  int qstate = 0;
  int count;
  string accno,
  pinno;
  int i = 0;
  string name;
  string adhar,
  email,
  acc_type,
  address,
  phoneno;
  string amount;
  stringstream ss,
  sss,
  ssss;
  accno = gen_random_num(5);

  cout << "\n\n NEW ACCOUNT NO IS: " << accno;

  sss << "select * from banking where account_no  = '" + accno + "' ";
  string query = sss.str();
  const char * q = query.c_str();
  mysql_query(conn, q);
  res = mysql_store_result(conn);
  count = mysql_num_fields(res);
  my_ulonglong x = mysql_num_rows(res);
  if (x > 0) {
    cout << "RECORD ALERADY EXIST";
    goto on;

  } else {
    onn2: cout << "\n\nENTER ADHAAR CARD NUMBER: ";
    cin.ignore();
    getline(cin, adhar);
    if (number(adhar)) {
      goto sss3;
    } else {
      cout << "\n\n ACCOUNT NUMBER SHOULD BE 12 Digit AND NOT ALLOWED CHARACTERSTICS..";
      getch();
      system("cls");
      goto onn2;

    }
    sss3: ssss << "select * from banking where adharcardnum = '" + adhar + "' ";
    string queryy = ssss.str();
    const char * q1 = queryy.c_str();
    mysql_query(conn, q1);
    resss = mysql_store_result(conn);
    count = mysql_num_fields(resss);
    my_ulonglong xx = mysql_num_rows(resss);

    if (xx > 0) {
      cout << "\n\nRECORD ALERADY EXIST";

      while (row = mysql_fetch_row(resss)) {
        cout << "\n" << "\n ACCOUTt NO: " << row[1] << "\n NAME: " << row[2] << "\n EMAIL: " << row[3] << "\n PHONE NO: " << row[4] << "\n AMOUNT: " << row[6];

      }
      getch();
      bankmangement(conn);
    } else {

      p12333: cout << "\n\nENTER NAME:";
      getline(cin, name);
      system("cls");

      if (character(name)) {
        goto p121;

      } else {
        cout << "\nNUMBER AND SPECIAL CHARACTER IS NOT ALLAOW";
        goto p12333;

      }
      p121: tt:

        cout << "\n\nENTER EMAIL: ";
      getline(cin, email);
      system("cls");

      if (Email(email)) {
        goto s;

      } else {
        cout << "VALID EMAIL ID ALLWOED " << endl;
        goto tt;

      }
      s: cout << "\n\nENTER ACCOUNT TYPE  (C/S): ";
      cin >> acc_type;
      if (acctype(acc_type)) {
        goto ttt;
      } else {
        goto s;
      }
      ttt: cout << "\n\nENTER phone NO: ";
      getline(cin, phoneno);
      system("cls");

      if (number_ten(phoneno)) {
        goto phh;

      } else {
        cout << "\nMOBILE NO IS ALLOWED TO ONLY 10 DIGIT." << endl;
        goto ttt;

      }
      phh: cout << "\n\nENTER ADDRESS : ";
      getline(cin, address);
      f12: cout << "\n\n AMOUNT:";
      getline(cin, amount);
      system("cls");

      if (number_only(amount)) {

        goto tt22;

      } else {
        cout << "NOT ALLOWED CHARACTER" << endl;
        goto f12;
      }

      tt22:

        pinno = gen_random_num(4);

      cout << "\n\n ATM PIN NO IS:" << pinno;
      cout << "\n\n NEW ACCOUNT NO IS: " << accno;

      ss << "INSERT INTO `banking` (`account_no`, `name`, `email`, `phoneno`, `account_type`, `amount`, `pinno`, `address`, `adharcardnum`) VALUES ('" + accno + "', '" + name + "', '" + email + "', '" + phoneno + "', '" + acc_type + "', '" + amount + "', '" + pinno + "', '" + address + "','" + adhar + "')";
      string query = ss.str();
      const char * q = query.c_str();
      qstate = mysql_query(conn, q);
      if (qstate == 0) {

        cout << "\n\nRECORD INSERTED SUCESSFULL";
      } else {
        cout << "\n\n FAILED";
      }

    }
  }

  /*
      int qstate = 0;
      int phoneno;

      string name,pass;
      stringstream ss;



      cout<<"\n\nENTER NAME: ";
      cin>>name;

      cout<<"\n\nENTER pass: ";
      cin>>pass;
       cout<<"\n\nENTER pass: ";
      cin>>phoneno;



      ss << "INSERT INTO ta (`name`, `pass`,`phno`) VALUES ('"+name+"', '"+pass+"','"+phoneno+"')";
      string query=ss.str();
      const char* q = query.c_str();
      qstate = mysql_query(conn,q);
      if(qstate==0)
      {

          cout<<"RECORD INSERTED SUCESSFULL";
      }
      else
      {
          cout<<"FAILED";
      }
  */

}

string bank::displayrecords(MYSQL * conn) {
  MYSQL_ROW row;
  MYSQL_RES * res;
  if (conn) {
    int qstate = mysql_query(conn, "SELECT * FROM `banking`");
    if (!qstate) {
      res = mysql_store_result(conn);
      int count = mysql_num_fields(res);
      while (row = mysql_fetch_row(res)) {
        for (int i = 0; i < count; i++) {

          cout << "\t" << row[i];
        }
        cout << endl;
      }

    }
  } else {
    cout << "failed to fetch";
  }

}

string bank::deleterecord(MYSQL * conn) {
  MYSQL_ROW row;
  MYSQL_RES * res;

  string accno;
  stringstream ss, sss;
  cout << "\n\nENTER ACCOUNT NO : ";
  cin >> accno;
  sss << "select * from banking where account_no = '" + accno + "' ";
  string query = sss.str();
  const char * q = query.c_str();
  mysql_query(conn, q);
  res = mysql_store_result(conn);
  int count = mysql_num_fields(res);
  my_ulonglong x = mysql_num_rows(res);

  if (x > 0) {
    while (row = mysql_fetch_row(res)) {
      cout << "\n" << "\n ACCOUTt NO: " << row[1] << "\n NAME: " << row[2] << "\n EMAIL: " << row[3] << "\n PHONE NO: " << row[4] << "\n AMOUNT: " << row[6];

      ss << "DELETE FROM `banking` WHERE account_no='" + accno + "' ";
      string query = ss.str();
      const char * q = query.c_str();
      mysql_query(conn, q);
      //ss<<"DELETE FROM hacker WHERE name='"+name+"'";
      cout << "\n\nRECORD DELETED SUCESSFULLY" << row[2];
    }

  } else {
    cout << "ERROR";

  }
}

string bank::updaterecord(MYSQL * conn) {
  p: string choice;
  system("cls");
  system("Color 0F");
  cout << "\n\n 1. UPDATE NAME";
  cout << "\n\n 2. UPDATE ADHAAR NUMBER ";
  cout << "\n\n 3. UPDATE PHONE NUMBER ";
  cout << "\n\n 4. UPDATE ADDRESS ";
  cout << "\n\n 5. UPDATE EMAIL ";
  cout << "\n\n 6. GO BACK ";

  cout << "\n\n\t WHICH RECORD YOU HAVE UPDATED PLEASE SELECT: ";
  cin >> choice;

  if (number_onl(choice)) {
    goto sd;
  } else {
    system("Color 0C");
    cout << "\n\nINVALID INPUT PLEASE TRY AGAIN.... SELECT ONLY [1 to 6] BETWEEN ";
    PlaySound(TEXT("error.wav"), NULL, SND_SYNC);
    getch();
    goto p;
  }
  sd: int num = stoi(choice);
  switch (num) {
  case 1:
    update_name(conn);
    break;

  case 2:
    update_adhar(conn);
    break;

  case 3:
    update_mobno(conn);
    break;

  case 4:
    update_address(conn);
    break;

  case 5:
    update_email(conn);
    break;

  case 6:
    bankmangement(conn);
    break;

  default:
    cout << "\nINVALID INPUT PLEASE TRY AGAIN.... SELECT ONLY [1 to 6] BETWEEN";
    system("Color 0C");
    PlaySound(TEXT("error.wav"), NULL, SND_SYNC);

    break;

  }

  getch();
  goto p;

}

string bank::update_name(MYSQL * conn) {
  MYSQL_ROW row;
  MYSQL_RES * res;

  string acno;
  stringstream ss, sss;
  string new_name;
  system("cls");
  cout << "\n\nENTER USER ACCOUNT NO: ";
  cin >> acno;
  sss << "select * from banking where account_no = '" + acno + "' ";
  string query = sss.str();
  const char * q = query.c_str();
  mysql_query(conn, q);
  res = mysql_store_result(conn);
  int count = mysql_num_fields(res);
  my_ulonglong x = mysql_num_rows(res);

  if (x > 0) {

    while (row = mysql_fetch_row(res)) {
      ss: cout << " NAME IS:\t" << row[2];
      cin.ignore();
      cout << "\n\nENTER NEW NAME : ";
      getline(cin, new_name);

      if (character(new_name)) {

        goto p;
      } else {

        cout << "\n\nDIGITS AND SPECIAL CHARACTER ARE NOT ALLOWED";
        getch();
        system("CLS");
        goto ss;
      }
      p: ss << "UPDATE banking SET name = '" + new_name + "' WHERE account_no = '" + acno + "'";
      string query = ss.str();
      const char * q = query.c_str();
      mysql_query(conn, q);
      cout << "\n\n NAME UPDATED SUCESSFULLY \t" << new_name;

    }
  } else {
    cout << "ERROR";
  }

}

string bank::update_adhar(MYSQL * conn) {
  MYSQL_ROW row;
  MYSQL_RES * res;

  string acno;
  string adhar_up;
  stringstream ss, sss;
  system("cls");
  cout << "\n\nENTER ACCOUNT NO: ";
  cin >> acno;
  sss << "select * from banking where account_no = '" + acno + "' ";

  string query = sss.str();
  const char * q = query.c_str();
  mysql_query(conn, q);
  res = mysql_store_result(conn);
  int count = mysql_num_fields(res);
  my_ulonglong x = mysql_num_rows(res);

  if (x > 0) {
    while (row = mysql_fetch_row(res)) {
      o: cout << "\nOLD ADHAR NUMBER IS:" << row[9];
      cout << "\n\nENTER NEW ADHAR NUMBER: ";
      cin >> adhar_up;
      if (number(adhar_up)) {
        goto s;
      } else {
        cout << "\n\n ONLY 12 DIGITS ARE ALLOWED SPACES ARE NOT ALLOW....";
        getch();
        system("cls");
        goto o;
      }

      s: ss << "UPDATE banking SET adharcardnum = '" + adhar_up + "' WHERE account_no = '" + acno + "'";
      string query = ss.str();
      const char * q = query.c_str();
      mysql_query(conn, q);
      cout << "\n\nADHAR NUMBER UPDATED SUCESSFULLY\t" << adhar_up;
    }
  } else {
    cout << "\nINVLAID ACCOUNT NO.....";

  }
}

string bank::update_mobno(MYSQL * conn) {
  MYSQL_ROW row;
  MYSQL_RES * res;

  string acno;
  stringstream ss, sss;
  cout << "\n\nENTER ACCOUNT NO: ";
  cin >> acno;
  sss << "select * from banking where account_no = '" + acno + "' ";

  string query = sss.str();
  const char * q = query.c_str();
  mysql_query(conn, q);
  res = mysql_store_result(conn);
  int count = mysql_num_fields(res);
  my_ulonglong x = mysql_num_rows(res);

  if (x > 0) {
    while (row = mysql_fetch_row(res)) {
      sg: cout << "\nYOUR OLD MOBILE NUMBER IS:" << row[4];

      string mob;
      cout << "\n\nENTER NEW MOBILE NO : ";
      cin >> mob;
      if (number_ten(mob)) {

        goto sa;

      } else {
        cout << "\n\n ONLY 10 DIGITS ARE ALLOWED. SPACES ARE NOT ALLOW....";
        getch();
        system("cls");
        goto sg;
      }

      sa: ss << "UPDATE banking SET phoneno = '" + mob + "' WHERE account_no = '" + acno + "'";
      string query = ss.str();
      const char * q = query.c_str();
      mysql_query(conn, q);
      cout << "\n\nYOUR MOBILE NUMBER UPDATED SUCESSFULLY\t" << mob;

    }
  } else {
    cout << "\nINVLAID ACCOUNT NO.....";

  }

}

string bank::update_email(MYSQL * conn) {
  MYSQL_ROW row;
  MYSQL_RES * res;

  string acno;
  stringstream ss, sss;
  cout << "\n\nENTER ACCOUNT NO: ";
  cin >> acno;
  sss << "select * from banking where account_no = '" + acno + "' ";

  string query = sss.str();
  const char * q = query.c_str();
  mysql_query(conn, q);
  res = mysql_store_result(conn);
  int count = mysql_num_fields(res);
  my_ulonglong x = mysql_num_rows(res);

  if (x > 0) {
    while (row = mysql_fetch_row(res)) {
      sg: cout << "YOUR OLD EMAIL ID IS:" << row[3];
      string email;

      cout << "\n\nENTER NEW EMAIL ID : ";
      cin >> email;

      if (Email(email)) {
        goto as;

      } else {
        cout << "\n\n INVALID EMAIL ID.....";
        getch();
        system("cls");
        goto sg;
      }
      as: ss << "UPDATE banking SET email = '" + email + "' WHERE account_no = '" + acno + "'";
      string query = ss.str();
      const char * q = query.c_str();
      mysql_query(conn, q);
      cout << "YOUR NEW EMAIL ID UPDATED SUCESSFULLY " << email;
    }
  } else {
    cout << "\n\nINVLAID ACCOUNT NO.....";

  }
}

string bank::update_address(MYSQL * conn) {
  MYSQL_ROW row;
  MYSQL_RES * res;

  string acno;
  stringstream ss, sss;
  string address_upd;
  system("cls");
  cout << "\n\nENTER ACCOUNT NUMBER: ";
  cin >> acno;
  sss << "select * from banking where account_no = '" + acno + "' ";

  string query = sss.str();
  const char * q = query.c_str();
  mysql_query(conn, q);
  res = mysql_store_result(conn);
  int count = mysql_num_fields(res);
  my_ulonglong x = mysql_num_rows(res);

  if (x > 0) {
    while (row = mysql_fetch_row(res)) {
      cout << "\n YOUR OLD ADDRESS IS:" << row[8];
    }

    cout << "\n\nENTER NEW ADDRESS : ";
    cin.ignore();
    getline(cin, address_upd);

    ss << "UPDATE banking SET address = '" + address_upd + "' WHERE account_no = '" + acno + "'";
    string query = ss.str();
    const char * q = query.c_str();
    mysql_query(conn, q);
    cout << "YOUR ADDRESS UPDATED SUCESSFULLY " << address_upd;
  } else {
    cout << "ERROR";

  }
}

string bank::showspecificrecord(MYSQL * conn) {
  MYSQL_ROW row;
  MYSQL_RES * res;

  int acno;
  int amt;
  system("cls");
  stringstream ss, sss;
  cout << "\n\nENTER acno: ";
  cin >> acno;
  string str = to_string(acno);

  sss << "select * from banking where account_no = '" + str + "' ";

  string query = sss.str();
  const char * q = query.c_str();
  mysql_query(conn, q);
  res = mysql_store_result(conn);
  int count = mysql_num_fields(res);
  my_ulonglong x = mysql_num_rows(res);

  if (x > 0) {

    while (row = mysql_fetch_row(res)) {
      cout << "\n ID: " << row[0] << "\n ACCOUTt NO: " << row[1] << "\n NAME: " << row[2] << "\n EMAIL: " << row[3] << "\n PHONE NO: " << row[4] << "\n AMOUNT: " << row[6];

    }

  } else {
    cout << "ERROR";

  }

}

string bank::depositamt(MYSQL * conn) {
  MYSQL_ROW row;
  MYSQL_RES * res;

  string acno;
  string amt;
  system("cls");
  stringstream ss, sss, tt;
  cout << "\n\nENTER acno: ";
  cin >> acno;
  sss << "select * from banking where account_no  = '" + acno + "' ";

  string query = sss.str();
  const char * q = query.c_str();
  mysql_query(conn, q);
  res = mysql_store_result(conn);
  int count = mysql_num_fields(res);
  my_ulonglong x = mysql_num_rows(res);

  if (x > 0) {

    while (row = mysql_fetch_row(res)) {
      sst: cout << "\n ID: " << row[0] << "\n ACCOUNT NO: " << row[1] << "\n NAME: " << row[2] << "\n EMAIL: " << row[3] << "\n PHONE NO: " << row[4] << "\n AMOUNT: " << row[6];
      cout << "\n\nENTER AMOUNT : ";
      cin >> amt;
      if (number_only(amt)) {
        goto pp;

      } else {
        goto sst;
      }

      pp: int num1 = stoi(row[6]);
      int num3 = stoi(amt);

      int ta;
      ta = num1;
      ta += num3;
      string tau = to_string(ta);
      ss << "UPDATE banking SET amount = '" + tau + "' WHERE account_no = '" + acno + "'";
      string query = ss.str();
      const char * q = query.c_str();
      mysql_query(conn, q);
      cout << "\n\n\t" << amt << " AMOUNT DEPOSITED SUCESSFULLY.... " << "\n\n\t REMANING AMOUNT IS: " << tau;
      tt << "INSERT INTO `trans_hist` ( `accno`, `deposit_amt`, `withdraw_amt`,`remain_amt`,`transaction_mode`) VALUES ('" + acno + "', '" + amt + "', ' ', '" + tau + "','bank')";
      query = tt.str();
      q = query.c_str();
      mysql_query(conn, q);
    }

  } else {
    cout << "\n\nINVALID ACCOUNT NO....";

  }

}

string bank::withdrawamt(MYSQL * conn) {
  MYSQL_ROW row;
  MYSQL_RES * res;

  string acno;
  string amt;
  system("cls");
  stringstream ss, sss, tt;
  cout << "\n\nENTER acno: ";
  cin >> acno;

  sss << "select * from banking where account_no = '" + acno + "' ";

  string query = sss.str();
  const char * q = query.c_str();
  mysql_query(conn, q);
  res = mysql_store_result(conn);
  int count = mysql_num_fields(res);
  my_ulonglong x = mysql_num_rows(res);

  if (x > 0) {

    while (row = mysql_fetch_row(res)) {
      as: cout << "\n ID: " << row[0] << "\n ACCOUNT NO: " << row[1] << "\n NAME: " << row[2] << "\n EMAIL: " << row[3] << "\n PHONE NO: " << row[4] << "\n AMOUNT: " << row[6];
      cout << "\n\nENTER AMOUNT : ";
      cin >> amt;
      if (number_only(amt)) {
        goto n;
      } else {
        cout << "\n\nONLY NUMBERS ARE ALLOWED";
        getch();
        system("CLS");
        goto as;
      }

      n: int num1 = stoi(row[6]);
      int num2 = stoi(amt);

      if (num2 < num1) {
        int ta;
        ta = num1;
        ta -= num2;
        string tau = to_string(ta);

        ss << "UPDATE banking SET amount = '" + tau + "' WHERE account_no = '" + acno + "'";
        string query = ss.str();
        const char * q = query.c_str();
        mysql_query(conn, q);
        cout << "\n\n\t" << amt << " AMOUNT WITHDRAW SUCESSFULLY.... " << "\n\n\t REMANING AMOUNT IS: " << tau;

        tt << "INSERT INTO `trans_hist` ( `accno`, `deposit_amt`, `withdraw_amt`,`remain_amt`,`transaction_mode`) VALUES ('" + acno + "', ' ', '" + amt + "', '" + tau + "','bank')";
        query = tt.str();
        q = query.c_str();
        mysql_query(conn, q);
      } else {
        cout << "\n\nLOW BALANCE...." << row[6];

      }
    }

  } else {
    cout << "\n\nINVALID ACCOUNT NO....";

  }

}

string bank::transfer_amt(MYSQL * conn) {

  MYSQL_ROW row;
  MYSQL_ROW roww;
  MYSQL_RES * res;
  MYSQL_RES * ress;

  string acno_1, acno_2;
  string amt;
  int count;
  system("cls");
  stringstream ss, sss, ssss, tss, tt, ttt;
  cout << "\n\nENTER SENDER ACCOUNT NO: ";
  cin >> acno_1;
  cout << "\n\nENTER RECIVER ACCOUNT NO: ";
  cin >> acno_2;
  if (acno_1 == acno_2) {
    cout << "\n SAME ACCOUNT NUMBERS ARE NOT ALLOWED.....";
    getch();
    bankmangement(conn);
  } else {
    goto sa;
  }

  sa:

    sss << "select * from banking where account_no = '" + acno_1 + "' ";

  string query = sss.str();
  const char * q = query.c_str();
  mysql_query(conn, q);
  res = mysql_store_result(conn);
  count = mysql_num_fields(res);
  my_ulonglong x = mysql_num_rows(res);

  ssss << "select * from banking where account_no = '" + acno_2 + "' ";

  string queryy = ssss.str();
  const char * qq = queryy.c_str();
  mysql_query(conn, qq);
  ress = mysql_store_result(conn);
  count = mysql_num_fields(ress);
  my_ulonglong xx = mysql_num_rows(ress);

  if (x > 0 && xx > 0) {

    while (row = mysql_fetch_row(res)) {
      while (roww = mysql_fetch_row(ress)) {

        cout << "\n\nENTER AMOUNT : ";
        cin >> amt;

        int num1 = stoi(row[6]);
        int num3 = stoi(roww[6]);
        int num2 = stoi(amt);

        if (num2 < num1) {
          int ta, fa;
          ta = num1;
          ta -= num2;
          string tau = to_string(ta);
          ss << "UPDATE banking SET amount = '" + tau + "' WHERE account_no = '" + acno_1 + "'";
          string query = ss.str();
          const char * q = query.c_str();
          mysql_query(conn, q);
          fa = num3;
          fa += num2;
          string taus = to_string(fa);
          tss << "UPDATE banking SET amount = '" + taus + "' WHERE account_no = '" + acno_2 + "'";
          string queryq = tss.str();
          const char * qw = queryq.c_str();
          mysql_query(conn, qw);

          cout << "\n\nMONEY TRANSFERED SUCESSFULLY....";

          tt << "INSERT INTO `trans_hist` ( `accno`, `deposit_amt`, `withdraw_amt`,`remain_amt`,`transaction_mode`) VALUES ('" + acno_1 + "', ' ', '" + amt + "', '" + tau + "', 'send " + acno_2 + "')";
          query = tt.str();
          q = query.c_str();
          mysql_query(conn, q);

          ttt << "INSERT INTO `trans_hist` ( `accno`, `deposit_amt`, `withdraw_amt`,`remain_amt`,`transaction_mode`) VALUES ('" + acno_2 + "', '" + amt + "', ' ', '" + taus + "','recieve " + acno_1 + "')";
          query = ttt.str();
          q = query.c_str();
          mysql_query(conn, q);

        } else {
          cout << "\n\nLOW BALANCE...." << row[6];

        }
      }
    }
  } else {
    cout << "\n\nINVALID ACCOUNTS NO....";

  }

}

string bank::trans_hist(MYSQL * conn) {

  MYSQL_ROW row;
  MYSQL_RES * res;

  string acno;
  int amt;
  fstream file;
  system("cls");
  stringstream ss, sss;
  cout << "\n\nENTER acno: ";
  cin >> acno;
  //string str= to_string(acno);
  sss << "select * from trans_hist where accno = '" + acno + "' ";

  string query = sss.str();
  const char * q = query.c_str();
  mysql_query(conn, q);
  res = mysql_store_result(conn);
  int count = mysql_num_fields(res);
  my_ulonglong x = mysql_num_rows(res);
  string asss = acno += ".txt";

  if (x > 0) {

    cout << "\n" << "ACCOUNT NO " << setw(10) << "DEPOSIT" << setw(20) << "WITHDRAW" << "\t" << "REMAIN AMT" << "\t" << "LOCATION" << setw(50) << "DATE AND TIME";

    while (row = mysql_fetch_row(res)) {
      cout << "\n" << row[1] << setw(10) << row[2] << setw(20) << row[3] << "\t\t" << row[4] << "\t\t" << row[5] << setw(50) << row[6];

    }

  } else {
    cout << "\nINVLAID ACCOUNT NO.........";

  }

}

string bank::trans_hist_download(MYSQL * conn) {

  MYSQL_ROW row;
  MYSQL_RES * res;

  string acno;
  fstream file;
  system("cls");
  stringstream ss, sss;
  cout << "\n\nENTER acno: ";
  cin >> acno;

  //string str= to_string(acno);
  sss << "select * from trans_hist where accno = '" + acno + "' ";

  string query = sss.str();
  const char * q = query.c_str();
  mysql_query(conn, q);
  res = mysql_store_result(conn);
  int count = mysql_num_fields(res);
  my_ulonglong x = mysql_num_rows(res);
  srand((unsigned) time(0));

  time_t now = time(0);
  char * dt = ctime( & now);

  string att = "C:/Users/tausi/Documents/hackingbank/transction/"
  " " + acno + " " + gen_random(2) += ".xls";
  file.open(att, ios:: in );

  if (x > 0) {
    file.open(att, ios::app | ios::out);
    file << dt << "\n\n\n";
    file << "\n" << "ACCOUNT NO " << setw(10) << "DEPOSIT" << setw(20) << "WITHDRAW" << "\t" << "REMAIN AMT" << "\t" << "LOCATION" << setw(50) << "DATE AND TIME\n\n";

    while (row = mysql_fetch_row(res)) {
      file << " " << row[1] << " " << row[2] << " " << row[3] << " " << row[4] << " " << row[5] << " " << row[6] << "\n";

    }
    cout << "PLEASE WAIT YOUR FILE DOWNLOADING";

    for (int i = 0; i < 3; i++) {

      for (int i = 0; i < 2; i++) {
        Sleep(1000);
        cout << ".";

      }

    }
    cout << "\n\nYOUR FILE DOWNLOAD SUCCESSFULLY....";
    file.close();

  } else {
    cout << "\nINVLAID ACCOUNT NO OR TRANSACTIONS NOT AVALABLE.........";

  }

}


/*ATM MANAGEMENT LOGIC */

string bank::atmmangement(MYSQL * conn) {
  if (conn) {
    p: string choice;
    system("cls");
    system("Color 0F");
    cout << "\n\n 1. CHECK BANK BALANCE ";
    cout << "\n\n 2. DEPOSITE AMOUNT ";
    cout << "\n\n 3. WITHDRAW AMOUNT ";
    cout << "\n\n 4. CHECK MY DETAILS ";
    cout << "\n\n 5. CHANGE PIN ";
    cout << "\n\n 6. FORGOT PIN";
    cout << "\n\n 7. goback ";

    cout << "\n\nENTER YOUR CHOICE: ";
    cin >> choice;

    if (number_onl(choice)) {

      goto sd;
    } else {
      system("Color 0C");
      cout << "\n\nINVALID INPUT PLEASE TRY AGAIN SELECT [1 to 5] BETWEEN ";
      PlaySound(TEXT("error.wav"), NULL, SND_SYNC);
      getch();
      goto p;

    }
    sd: int num = stoi(choice);
    switch (num) {

    case 1:
      checkbalance(conn);
      break;

    case 2:
      depositamt_atm(conn);
      break;

    case 3:
      withdrawamt_atm(conn);
      break;

    case 4:
      showspecificrecord(conn);
      break;

    case 5:
      changepin_atm(conn);
      break;

    case 6:
      forgotpin_atm(conn);
      break;

    case 7:
      menu(conn);

    default:
      cout << "\n\nINVALID INPUT PLEASE TRY AGAIN SELECT [1 to 5] BETWEEN ";
      system("Color 0C");
      PlaySound(TEXT("error.wav"), NULL, SND_SYNC);

    }

    getch();
    goto p;
    return 0;

  }
  else {
    cout << "CONNECTION FAILED";
  }

}

string bank::depositamt_atm(MYSQL * conn) {
  MYSQL_ROW row;
  MYSQL_RES * res;

  string acno;
  string amt;
  system("cls");
  stringstream ss, sss, tt;
  cout << "\n\nENTER acno: ";
  cin >> acno;
  sss << "select * from banking where account_no  = '" + acno + "' ";
  string query = sss.str();
  const char * q = query.c_str();
  mysql_query(conn, q);
  res = mysql_store_result(conn);
  int count = mysql_num_fields(res);
  my_ulonglong x = mysql_num_rows(res);

  if (x > 0) {

    while (row = mysql_fetch_row(res)) {
      sst: cout << "\nACCOUNT NO: " << row[1] << "\n NAME: " << row[2];
      cout << "\n\nENTER AMOUNT : ";
      cin >> amt;
      if (number_only(amt)) {
        goto pp;

      } else {
        goto sst;
      }

      pp: int num1 = stoi(row[6]);
      int num3 = stoi(amt);

      int ta;
      ta = num1;
      ta += num3;
      string tau = to_string(ta);
      ss << "UPDATE banking SET amount = '" + tau + "' WHERE account_no = '" + acno + "'";
      string query = ss.str();
      const char * q = query.c_str();
      mysql_query(conn, q);
      cout << "\n\n\t" << amt << " AMOUNT DEPOSITED SUCESSFULLY.... " << "\n\n\t REMANING AMOUNT IS: " << tau;
      tt << "INSERT INTO `trans_hist` ( `accno`, `deposit_amt`, `withdraw_amt`,`remain_amt`,`transaction_mode`) VALUES ('" + acno + "', '" + amt + "', ' ', '" + tau + "','ATM')";
      query = tt.str();
      q = query.c_str();
      mysql_query(conn, q);
      getch();
      atmmangement(conn);
    }

  } else {
    cout << "\n\nINVALID ACCOUNT NO....";

  }

}

unsigned long _stdcall Timer();
string bank::withdrawamt_atm(MYSQL * conn) {
  sa: MYSQL_ROW row;
  MYSQL_RES * res;

  string acno,
  pinno;
  int amt;
  system("cls");
  stringstream ss,
  sss,
  tt;
  cout << "\n\nENTER acno: ";
  cin >> acno;
  if (number_only(acno)) {
    goto pps;

  } else {

    goto sa;
  }
  pps:

    sss << "select * from banking where account_no = '" + acno + "' ";

  string query = sss.str();
  const char * q = query.c_str();
  mysql_query(conn, q);
  res = mysql_store_result(conn);
  int count = mysql_num_fields(res);
  my_ulonglong x = mysql_num_rows(res);

  if (x > 0) {

    while (row = mysql_fetch_row(res)) {
      cout << "\n\nENTER pinno: ";
      cin >> pinno;

      if (pinno == row[7]) {
        ks: cout << "\n" << "\n ACCOUNT NO: " << row[1] << "\n NAME: " << row[2] << "\n EMAIL: " << row[3] << "\n PHONE NO: " << row[4] << "\n AMOUNT: " << row[6];

           HANDLE hTimer = NULL;

/*unsigned long _stdcall Timer()
{
    int nCount = 0;
    while(nCount < 10)
    {
    WaitForSingleObject(hTimer, 5000);
    nCount++;
    }
    cout << "50 secs\n";
    atmmangement(conn);
}
    DWORD tid;
    hTimer = CreateEvent(NULL, FALSE, FALSE, NULL);
    CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)Timer,NULL,0,&tid);*/
//CreateThread(NULL, 0, &Timer, NULL, 0, &tid);

        cout << "\n\nENTER AMOUNT : ";
        //string tau = to_string(amt);

cin>>amt;
       /* while(cin >> amt)
    {
        if(0==amt)
            SetEvent(hTimer);

    }*/
    CloseHandle(hTimer);
       /* if (number_only(tau)) {
          goto sps;

        } else {
          cout << "ONLY DIGITS ARE ALLWOED.....";
          getch();
          system("cls");
          goto ks;
        }
        sps:
        int amt = stoi(tau);
*/
        if (amt > 10000) {
          cout << "YOU CAN WITHDRAW ONLY LESS THAN 10000 Rs.";
          getch();
          system("cls");
          goto ks;

        } else {
          int num1 = stoi(row[6]);
          if (amt < num1) {
            int ta;
            ta = num1;
            ta -= amt;
            string tau = to_string(ta);
            ss << "UPDATE banking SET amount = '" + tau + "' WHERE account_no = '" + acno + "'";
            string query = ss.str();
            const char * q = query.c_str();
            mysql_query(conn, q);
            PlaySound(TEXT("withdraw.wav"), NULL, SND_SYNC);
            string sst = to_string(amt);
            cout << "\n\n\t" << amt << " AMOUNT WITHDRAW SUCESSFULLY.... " << "\n\n\t REMANING AMOUNT IS: " << tau;
            tt << "INSERT INTO `trans_hist` ( `accno`, `deposit_amt`, `withdraw_amt`,`remain_amt`,`transaction_mode`) VALUES ('" + acno + "', ' ', '" + sst + "', '" + tau + "','ATM')";
            query = tt.str();
            q = query.c_str();
            mysql_query(conn, q);
          } else {
            cout << "\n\nLOW BALANCE...." << row[6];

          }
        }
      }
      else {
        cout << "\n\nINVALID PIN NO......";
        getch();
        atmmangement(conn);
      }
    }

  } else {
    cout << "\n\nINVALID ACCOUNT NO....";
    getch();
    atmmangement(conn);

  }

}

string bank::checkbalance(MYSQL * conn) {
  MYSQL_ROW row;
  MYSQL_RES * res;

  int acno;
  int amt;
  system("cls");
  stringstream ss, sss;
  cout << "\n\nENTER acno: ";
  cin >> acno;
  string str = to_string(acno);

  sss << "select * from banking where account_no = '" + str + "' ";

  string query = sss.str();
  const char * q = query.c_str();
  mysql_query(conn, q);
  res = mysql_store_result(conn);
  int count = mysql_num_fields(res);
  my_ulonglong x = mysql_num_rows(res);

  if (x > 0) {

    while (row = mysql_fetch_row(res)) {

      cout << "\n\n\t\t\tWELCOME " << row[2];
      cout << "\n" << "\n ACCOUTt NO: " << row[1] << "\n NAME: " << row[2] << "\n AMOUNT: " << row[6];
      getch();
      atmmangement(conn);

    }

  } else {
    cout << "ERROR";

  }

}

string bank::changepin_atm(MYSQL * conn) {

  sa: MYSQL_ROW row;
  MYSQL_RES * res;
  string acno,
  pinno;
  string pinno_new;
  system("cls");
  stringstream ss,
  sss;
  cout << "\n\nENTER acno: ";
  cin >> acno;
  if (number_only(acno)) {
    goto pps;

  } else {

    goto sa;
  }
  pps: sss << "select * from banking where account_no = '" + acno + "' ";
  string query = sss.str();
  const char * q = query.c_str();
  mysql_query(conn, q);
  res = mysql_store_result(conn);
  int count = mysql_num_fields(res);
  my_ulonglong x = mysql_num_rows(res);

  if (x > 0) {

    while (row = mysql_fetch_row(res)) {

      cout << "\n\nENTER pinno: ";
      cin >> pinno;

      if (pinno == row[7]) {
        sst: cout << "\n\n WELCOME : " << row[2];
        cout << "\n\nENTER NEW PIN NO : ";
        cin >> pinno_new;
        if (number_pin(pinno_new)) {
          ss << "UPDATE banking SET pinno = '" + pinno_new + "' WHERE account_no = '" + acno + "'";
          string query = ss.str();
          const char * q = query.c_str();
          mysql_query(conn, q);
          cout << "\n YOUR PIN NO UPDATED SUCESSFULLY " << pinno_new;

        } else {
          cout << "\n\nPIN NO ONLY 4 DIGIT..... ";
          getch();
          system("CLS");
          goto sst;

        }
      }
      else {
        cout << "\n\nINVALID PIN NO......";

      }
    }

  } else {
    cout << "\n\nINVALID ACCOUNT NO....";

  }

}

string bank::forgotpin_atm(MYSQL * conn) {
  sa: MYSQL_ROW row;
  MYSQL_RES * res;
  string acno,
  adharno,
  phoneno;
  string pinno_new;
  system("cls");
  stringstream ss,
  sss;
  cout << "\n\nENTER acno: ";
  cin >> acno;
  if (number_only(acno)) {
    goto pps;

  } else {

    goto sa;
  }
  pps: sss << "select * from banking where account_no = '" + acno + "' ";
  string query = sss.str();
  const char * q = query.c_str();
  mysql_query(conn, q);
  res = mysql_store_result(conn);
  int count = mysql_num_fields(res);
  my_ulonglong x = mysql_num_rows(res);

  if (x > 0) {
    while (row = mysql_fetch_row(res)) {

      cout << "\n\nENTER YOUR ADHARCARD NO: ";
      cin >> adharno;

      if (adharno == row[9]) {

        cout << "\n\nENTER YOUR PHONE NO: ";
        cin >> phoneno;

        if (phoneno == row[4]) {

          cout << "\n\n WELCOME : " << row[2];
          cout << "\n\nENTER NEW PIN NO : ";
          cin >> pinno_new;
          if (number_pin(pinno_new)) {
            ss << "UPDATE banking SET pinno = '" + pinno_new + "' WHERE account_no = '" + acno + "'";
            string query = ss.str();
            const char * q = query.c_str();
            mysql_query(conn, q);
            cout << "\n YOUR PIN NO UPDATED SUCESSFULLY " << pinno_new;

          } else {
            cout << "\n\nPIN NO ONLY 4 DIGIT..... ";
            getch();
            system("CLS");

          }
        } else {
          cout << "\n\n MOBILE NO IS INVALID..... ";

        }
      } else {
        cout << "\n\nINVALID ADHAR NO......";

      }
    }

  } else {
    cout << "\n\nINVALID ACCOUNT NO....";

  }
}

void gotoxy(int x, int y) {
  COORD d;
  d.X = x;
  d.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), d);
}
void printProgBar(int percent) {
  string bar;

  for (int i = 0; i < 50; i++) {
    if (i < (percent / 2)) {
      bar.replace(i, 1, "=");
    } else if (i == (percent / 2)) {
      bar.replace(i, 1, ">");
    } else {
      bar.replace(i, 1, " ");
    }
  }
  gotoxy(36, 14);

  cout << "WECOME TO THE TAUSIF AND SUPRIYA BANK....... ";

  gotoxy(30, 16);
  cout << ""
  "[" << bar << "] ";
  cout.width(3);
  cout << percent << "%     " << std::flush;
}

/*MAIN FUNCTION*/
int main() {

  MYSQL * conn = connectdatabase();
  bank obj;
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD a;
  a.X = 10;
  a.Y = 30;

  int N = 100;
  for (int i = 0; i < N; i++) {
    float p = (i / (float) N) * (float) 100;
    printProgBar(p);
    //cout << p << endl;
    Sleep(3.3);
  }
  printProgBar(100);
  SetConsoleScreenBufferSize(handle, a);
  obj.menu(conn);
}

/* END MAIN FUNCTION*/
