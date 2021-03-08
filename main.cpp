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

/* ENCRYPTED CODE*/
string encrypted(string admin)
{
string encrypted;
char key[5] = "abcd";
 for (int x=0; x < admin.size(); x++)
 {
  encrypted += admin[x] ^ key[x/100%30];
 }
 return encrypted;
}
/*END ENCRYPTED CODE*/

/*DECRYPTED CODE*/
string unencrypted(string admin)
{
string unencrypted;
char key[5] = "abcd";

 for (int x = 0; x < admin.size(); x++)
  {
  unencrypted += admin[x] ^ key[x/100%30];
  }
 return unencrypted;
}
/*END DECRYPTED CODE*/


void Date()
{
    time_t T = time(NULL);
    struct tm tm = *localtime(&T);
    cout << "";
    cout << "\tDate: " << tm.tm_mday << "/" << tm.tm_mon + 1 << "/" << tm.tm_year + 1900 << "\n";
}

void Time()
{
    time_t curr_time;
    curr_time = time(NULL);

    tm *tm_local = localtime(&curr_time);
    cout << "Time : " << tm_local->tm_hour << ":" << tm_local->tm_min << ":" << tm_local->tm_sec;
}

      /*RANDOM CHARACTER*/
      string gen_random(const int len) {

        string tmp_s;
        static
        const char alphanum[] = "ABCDEFGHIJKLMNOPQRSTU""abcdefghijklmnopqrstuvwxyz";

        srand((unsigned) time(NULL) * getpid());

        tmp_s.reserve(len);

        for (int i = 0; i < len; ++i)
          tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];

        return tmp_s;

      }

      /* ACCOUNT NO GENERATE CODE*/

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
      /**/


/* Trans_id NO GENERATE CODE*/

      string Trans_id_send(const int len) {

        string tmp_s;
        static
        const char alphanum[] = "1234567890""256789031";

        srand((unsigned) time(NULL) * getpid());

        tmp_s.reserve(len);

        for (int i = 0; i < len; ++i)
          tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];

        return tmp_s;

      }


      string Trans_id_recive(const int len) {

        string tmp_s;
        static
        const char alphanum[] = "7824854265""25678903";

        srand((unsigned) time(NULL) * getpid());

        tmp_s.reserve(len);

        for (int i = 0; i < len; ++i)
          tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];

        return tmp_s;

      }


        string Trans_id_withdraw(const int len) {

        string tmp_s;
        static
        const char alphanum[] = "858047567894265""25678903";

        srand((unsigned) time(NULL) * getpid());

        tmp_s.reserve(len);

        for (int i = 0; i < len; ++i)
          tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];

        return tmp_s;

      }



       string Trans_id_deposit(const int len) {

        string tmp_s;
        static
        const char alphanum[] = "68545876310487""2597109103";

        srand((unsigned) time(NULL) * getpid());

        tmp_s.reserve(len);

        for (int i = 0; i < len; ++i)
          tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];

        return tmp_s;

      }


      /*trans id end*/

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
    /*CLASS END*/

    string bank::menu(MYSQL * conn) {
      if (conn) {
        p: system("cls");
        Time();
        Date();
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
        //cout << "\n\n 2.ATM MANAGEMENT";
        cout << "\n\n 2.EXIT ";
        cout << "\n\n ENTER YOUR CHOICE: ";
        cin >> choi;
        if (number_onl(choi)) {

          goto sd;
        } else {
          system("Color 0C");
          cout << "\n\nINVALID INPUT PLEASE TRY AGAIN SELECT [1 and 2] BETWEEN  ";
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

       /* case 2:
          atmmangement(conn);
          break;*/

        case 2:
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
        cout << "\n\n 9. VIEW TRANSACATION HISTORY ";
        cout << "\n\n 10.TRANSACATION HISTORY DOWNLOAD";
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
/* insert record function */
string bank::insertrecord(MYSQL * conn) {
      on: MYSQL_ROW row;
      MYSQL_RES * res;
      MYSQL_RES * resss;
      system("cls");
      int qstate = 0;
      int count;
      string accno,pinno;
      int i = 0;
      string name,h;
      string adhar,email,acc_type,address,phoneno;
      string amount,pins,adhard;
      stringstream ss,sss,ssss;

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
        sss3:
        adhard = unencrypted(adhar);
        ssss << "select * from banking where adharcardnum = '" + adhard + "' ";
        string queryy = ssss.str();
        const char * q1 = queryy.c_str();
        mysql_query(conn, q1);
        resss = mysql_store_result(conn);
        count = mysql_num_fields(resss);
        my_ulonglong xx = mysql_num_rows(resss);

        if (xx > 0) {
          cout << "\n\nRECORD ALERADY EXIST";

          while (row = mysql_fetch_row(resss)) {
            cout << "\n" << "\n ACCOUNT NO: " << row[1] << "\n NAME: " << row[2] << "\n EMAIL: " << row[3] << "\n PHONE NO: " << row[4] << "\n AMOUNT: " << row[6];

          }
          getch();
          bankmangement(conn);
        } else {

          p12333:
        cout << "\n\nENTER NAME:";
          getline(cin, name);
          system("cls");

          if (character(name)) {
            goto p121;

          } else {
            cout << "\nNUMBER AND SPECIAL CHARACTER IS NOT ALLAOW";
            goto p12333;

          }
          p121:
          tt:

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
            cout<<"\n\nPLEASE TYPE ONLY LETTER S OR C";
            getch();
            system("cls");
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
          phh:
          cout << "\n\nENTER ADDRESS : ";
          getline(cin, address);
          f12:
          cout << "\n\n AMOUNT:";
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

            h = encrypted(adhar);

          cout << "\n\n ATM PIN NO IS:" << pinno;

          cout << "\n\n NEW ACCOUNT NO IS: " << accno;
          pins = encrypted(pinno);
          ss << "INSERT INTO `banking` (`account_no`, `name`, `email`, `phoneno`, `account_type`, `amount`, `pinno`, `address`, `adharcardnum`) VALUES ('" + accno + "', '" + name + "', '" + email + "', '" + phoneno + "', '" + acc_type + "', '" + amount + "', '" + pins + "', '" + address + "','" + h + "')";
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
/*insert record End*/


/* show all record function*/
    string bank::displayrecords(MYSQL * conn) {
      MYSQL_ROW row;
      MYSQL_RES * res;
      string adharde,pinde;
      if (conn) {
        int qstate = mysql_query(conn, "SELECT * FROM `banking`");
        if (!qstate) {
          res = mysql_store_result(conn);
          int count = mysql_num_fields(res);
          while (row = mysql_fetch_row(res)) {
            /*for (int i = 0; i < count; i++) {

              cout << "\t" << row[i];
            }*/
            adharde = unencrypted(row[9]);
            pinde = unencrypted(row[7]);
            cout << row[0]<<"\t"<< row[1]<<"\t"<< row[2] << "\t" << row[3] << "\t" << row[4]<< "\t" << row[5]<< "\t" << row[6]<< "\t" << pinde << "\t" << row[8]<< "\t" << adharde << "\t" << row[10]<<endl;
            cout << endl;
          }

        }
      } else {
        cout << "failed to fetch";
      }

    }
/* show all record end*/

/* delete specific record function*/
    string bank::deleterecord(MYSQL * conn) {
      MYSQL_ROW row;
      MYSQL_RES * res;

      string accno;
      stringstream ss, sss ,sssw;
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

          sssw << "DELETE FROM `trans_hist` WHERE accno ='" + accno + "' ";
          string queryy = sssw.str();
          const char *wq = queryy.c_str();
          mysql_query(conn, wq);
          //ss<<"DELETE FROM hacker WHERE name='"+name+"'";
          cout << "\n\nRECORD DELETED SUCESSFULLY" << row[2];
        }

      } else {
        cout << "ERROR";

      }
    }
/* delete specific record end*/


/*update specific record function*/
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
/* end update sepcific record*/

/*update name function */

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
/*end update name*/

/*update adhar function */
    string bank::update_adhar(MYSQL * conn) {
      MYSQL_ROW row;
      MYSQL_RES * res;

      string acno;
      string adhar_up,h,hh;
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

          o:
          hh=unencrypted(row[9]);
          cout << "\nOLD ADHAR NUMBER IS:" << hh;
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
          s:
          h=encrypted(adhar_up);
          ss << "UPDATE banking SET adharcardnum = '" + h + "' WHERE account_no = '" + acno + "'";
          string query = ss.str();
          const char * q = query.c_str();
          mysql_query(conn, q);
          cout << "\n\nADHAR NUMBER UPDATED SUCESSFULLY\t" << adhar_up;
        }
      } else {
        cout << "\nINVLAID ACCOUNT NO.....";

      }
    }
/* end update adhar */

/*update mobile number function*/
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
/*end update mobile number*/

/* update email id function */

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
    /*end update mail id*/

    /* update address function */

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
/* end update record  */

/* show specific record function */

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

      sss << "select * from banking where account_no = '" + str + "' OR adharcardnum = '"+str+"'";

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
/* end show specific record*/

/* deposit amount function bank */
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
          string trans_id;
          trans_id = Trans_id_deposit(10);

          tt << "INSERT INTO `trans_hist` ( `accno`, `deposit_amt`, `withdraw_amt`,`remain_amt`,`trans_id`,`transaction_mode`) VALUES ('" + acno + "', '" + amt + "', ' ', '" + tau + "','"+trans_id+"','bank')";
          query = tt.str();
          q = query.c_str();
          mysql_query(conn, q);
        }

      } else {
        cout << "\n\nINVALID ACCOUNT NO....";

      }

    }
    /* end deposit amount */

/* withdraw amount function bank */

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
          as:
        cout << "\n ID: " << row[0] << "\n ACCOUNT NO: " << row[1] << "\n NAME: " << row[2] << "\n EMAIL: " << row[3] << "\n PHONE NO: " << row[4] << "\n AMOUNT: " << row[6];
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

          n:
          int num1 = stoi(row[6]);
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

            tt << "INSERT INTO `trans_hist` (`trans_id`,`accno`, `deposit_amt`, `withdraw_amt`,`remain_amt`,`transaction_mode`) VALUES ('"+Trans_id_withdraw(10)+"', '" + acno + "', ' ', '" + amt + "', '" + tau + "','bank')";
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
    /* end withdraw amount  */


 /* transfer amount function */
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



        sss << "select * from banking where account_no = '" + acno_1 + "' ";

      string query = sss.str();
      const char * q = query.c_str();
      mysql_query(conn, q);
      res = mysql_store_result(conn);
      count = mysql_num_fields(res);
      my_ulonglong x = mysql_num_rows(res);



      if (x > 0 ) {
            cout << "\n\nENTER RECIVER ACCOUNT NO: ";
            cin >> acno_2;
            if (acno_1 == acno_2) {
        cout << "\n SAME ACCOUNT NUMBERS ARE NOT ALLOWED.....";
        getch();
        bankmangement(conn);
      }
    ssss << "select * from banking where account_no = '" + acno_2 + "' ";
      string queryy = ssss.str();
      const char * qq = queryy.c_str();
      mysql_query(conn, qq);
      ress = mysql_store_result(conn);
      count = mysql_num_fields(ress);
      my_ulonglong xx = mysql_num_rows(ress);


            if(xx>0)
            {

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

              tt << "INSERT INTO `trans_hist` ( `trans_id`, `accno`, `deposit_amt`, `withdraw_amt`,`remain_amt`,`transaction_mode`) VALUES ('"+Trans_id_send(10)+"', '" + acno_1 + "', ' ', '" + amt + "', '" + tau + "', 'send " + acno_2 + "')";
              query = tt.str();
              q = query.c_str();
              mysql_query(conn, q);
              cout<<"hello";

              ttt << "INSERT INTO `trans_hist` (`trans_id`, `accno`, `deposit_amt`, `withdraw_amt`,`remain_amt`,`transaction_mode`) VALUES ('"+Trans_id_recive(10)+"', '" + acno_2 + "', '" + amt + "', ' ', '" + taus + "','recieve " + acno_1 + "')";
              query = ttt.str();
              q = query.c_str();
              mysql_query(conn, q);
              cout<<"het";

            } else {
              cout << "\n\nLOW BALANCE...." << row[6];

            }
          }
        }
      } else {
        cout << "\n\nINVALID ACCOUNT NO....";

      }
      }else {
        cout << "\n\nINVALID ACCOUNT NO....";

      }

    }
/* end transfer amount */

/* view transaction history function */
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

        cout << "\n" << "Trans_id" << "\t\t"<< "ACCOUNT NO " << setw(15) << "DEPOSIT" << setw(25) << "WITHDRAW" << "\t" << "REMAIN AMT" << "\t" << "LOCATION" << setw(30) << "DATE AND TIME";

        while (row = mysql_fetch_row(res)) {
          cout << "\n"<< row[0] << "\t\t" << row[1] << setw(20) << row[2] << setw(20) << row[3] << "\t\t" << row[4] << "\t\t" << row[5] << setw(30) << row[6];

        }

      } else {
        cout << "\nINVLAID ACCOUNT NUMBER OR TRANSACTIONS NOT AVALABLE.........";

      }

    }
/* end transaction history */

/* transaction history download function */
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

      string att = "transction/"
      " " + acno + " " + gen_random(2) += ".doc";
      file.open(att, ios:: in );

      if (x > 0) {
        file.open(att, ios::app | ios::out);
        file << dt << "\n\n\n";
        file << "\n" << "accno " << setw(10) << "dep" << setw(20) << "withdraw" << "\t" << "remain_amt" << "\t" << "mode" << "\t\t" << "DATE_TIME\n\n";

        while (row = mysql_fetch_row(res)) {
          file<< row[1] << " \t" << row[2] << "\t   " << row[3] << "\t\t" << row[4] << "\t\t" << row[5] << "\t\t" << row[6] << "\n";

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
/* end transaction history download */


/*ATM MANAGEMENT LOGIC
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

/* deposit amount function atm
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
          sst:
          cout << "\nACCOUNT NO: " << row[1] << "\n NAME: " << row[2];
          cout << "\n\nENTER AMOUNT : ";
          cin >> amt;
          if (number_only(amt)) {
            goto pp;

          } else {
            cout<<"ALLOWED ONLY DIGITS....";
            getch();
            system("cls");
            goto sst;
          }

          pp:
          int num1 = stoi(row[6]);
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
        getch();
        atmmangement(conn);

      }

    }
    end deposit amount*/

/* withdraw amount function atm
    string bank::withdrawamt_atm(MYSQL* conn)
{
    sa:
    MYSQL_ROW row;
    MYSQL_RES* res;
    string acno,pinno,pindec;
    int amt;
    system("cls");
    stringstream ss,sss,ttwe;
    cout<<"\n\nENTER acno: ";
    cin>>acno;
     if(number_only(acno))
    {
        goto pps;

    }
    else{

        goto sa;
    }
    pps:



    sss<< "select * from banking where account_no = '"+acno+"' ";

    string query = sss.str();
    const char* q= query.c_str();
    mysql_query(conn , q);
    res = mysql_store_result(conn);
    int count = mysql_num_fields(res);
    my_ulonglong x = mysql_num_rows(res);




 if(x>0)
    {

         while(row = mysql_fetch_row(res)){
        bool s;
        s= row[10];
            cout<<"\n\nENTER pinno: ";
            cin>>pinno;
            pindec = unencrypted(row[7]);
            if(pinno == pindec ){
                    ks:
            cout<<"\n"<<"\n ACCOUNT NO: "<<row[1]<<"\n NAME: "<<row[2]<<"\n EMAIL: "<<row[3]<<"\n PHONE NO: "<<row[4]<<"\n AMOUNT: "<<row[6];
            cout<<"\n\nENTER AMOUNT : ";
            string tau= to_string(amt);

            cin>>tau;
            if(number_only(tau))
            {
            goto sps;

            }
            else{
            cout<<"ONLY DIGITS ARE ALLWOED.....";
            getch();
            system("cls");
            goto ks;
            }
            sps:
            int amt = stoi(tau);
            int rem ,divisor=100;
            rem = amt%divisor;
            if(rem == 0 && amt>=100){
                 goto ps;
            }
            else{

             cout<<"\n YOU CAN'T WITHDRAW MONEY....";
            getch();
             atmmangement(conn);

            }
            ps:
            if(amt>10000){

            cout<<"YOU CAN WITHDRAW ONLY LESS THAN 10000 Rs.";
            getch();
            system("cls");
                goto ks;

            }
            else{
            int num1 = stoi(row[6]);
            if(amt<num1)
            {
            int ta;
            ta=num1;
            ta-=amt;
            string tau= to_string(ta);
            ss<<"UPDATE banking SET amount = '"+tau+"' WHERE account_no = '"+acno+"'";
            string query = ss.str();
            const char* q= query.c_str();
            mysql_query(conn , q);
            PlaySound(TEXT("withdraw.wav"),NULL,SND_SYNC);
            string sst= to_string(amt);
            cout<<"\n\n\t"<< amt <<" AMOUNT WITHDRAW SUCESSFULLY.... "<<"\n\n\t REMANING AMOUNT IS: "<<tau;   ttwe<<"INSERT INTO `trans_hist` ( `accno`, `deposit_amt`, `withdraw_amt`,`remain_amt`,`transaction_mode`) VALUES ('"+acno+"', ' ', '"+sst+"', '"+tau+"','ATM')";
            int qstate=0;
            string queryyyy = ttwe.str();
            const char * qqw = queryyyy.c_str();
            qstate =  mysql_query(conn ,qqw);


         }

        else{
               cout<<"\n\nLOW BALANCE...."<<row[6];


        }
        }
        }
        else{
        cout<<"\n\nINVALID PIN NO......";
            getch();
              atmmangement(conn);
        }
            }


    }
    else{
              cout<<"\n\nINVALID ACCOUNT NO....";
              getch();
              atmmangement(conn);


    }


}

   end withdraw amount */

/* check balance function
    string bank::checkbalance(MYSQL * conn) {
      MYSQL_ROW row;
      MYSQL_RES * res;

      int acno;
      int amt;
      system("cls");
      stringstream ss, sss;
      string pinno,pinde;
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
            cout<<"\n ENTER PIN NO: ";
            cin>>pinno;
            pinde = unencrypted(row[7]);

          if(pinno == pinde){

          cout << "\n\n\t\t\tWELCOME " << row[2];
          cout << "\n" << "\n ACCOUNT NO: " << row[1] << "\n NAME: " << row[2] << "\n AMOUNT: " << row[6];
          getch();
          atmmangement(conn);

        }
        else{
        cout << "INVALID PIN NUMBER PLEASE TRY AGAIN.....";
        getch();
        atmmangement(conn);
        }

        }

      } else {
        cout << "INVALID ACCOUNT NUMBER PLEASE TRY AGAIN.....";
      }

    }

    string bank::changepin_atm(MYSQL * conn) {

      sa: MYSQL_ROW row;
      MYSQL_RES * res;
      string acno,
      pinno;
      string pinno_new,pinde,pinc;
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
          pinde=unencrypted(row[7]);

          if (pinno == pinde) {
            sst: cout << "\n\n WELCOME : " << row[2];
            cout << "\n\nENTER NEW PIN NO : ";
            cin >> pinno_new;
            if (number_pin(pinno_new)) {
              pinc = encrypted(pinno_new);
              ss << "UPDATE banking SET pinno = '" + pinc + "' WHERE account_no = '" + acno + "'";
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
      string acno,adharno,phoneno,adharencr,pinen;
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
          adharencr = unencrypted(row[9]);
          if (adharno == adharencr ) {

            cout << "\n\nENTER YOUR PHONE NO: ";
            cin >> phoneno;

            if (phoneno == row[4]) {

              cout << "\n\n WELCOME : " << row[2];
              cout << "\n\nENTER NEW PIN NO : ";
              cin >> pinno_new;
              if (number_pin(pinno_new)) {
                pinen = encrypted(pinno_new);
                ss << "UPDATE banking SET pinno = '" + pinen + "' WHERE account_no = '" + acno + "'";
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

*/

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
      /*HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD a;
      a.X = 10;
      a.Y = 30;
      SetConsoleScreenBufferSize(handle, a);*/
      HWND hwnd = GetConsoleWindow();
      ShowWindow(hwnd, SW_SHOWMAXIMIZED);

      int N = 100;
      for (int i = 0; i < N; i++) {
        float p = (i / (float) N) * (float) 100;
        printProgBar(p);
        //cout << p << endl;
        Sleep(3.3);
      }
      printProgBar(100);
      obj.menu(conn);
    }

    /* END MAIN FUNCTION*/
