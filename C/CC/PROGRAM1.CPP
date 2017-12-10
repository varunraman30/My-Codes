#include"program2.cpp"

void main()
 {
   fstream ff("Food.dat",ios::in|ios::out);
   food m1;
   int y=0;
   while(ff.read((char*)&m1,sizeof(m1)))
	e[y++]=m1;

    const int a=5,b=getmaxx()/2+220,c=getmaxx()/2+430;       																																																																																																																				     strcpy(log[0].user,"Varun");
    const int x=getmaxy()/4+150;                             																																																																																																																				     strcpy(log[0].pass,"Raman");

    int gdriver = DETECT, gmode;                             																																																																																																																				     strcpy(log[1].user,"Barry");
    initgraph(&gdriver, &gmode, "C:\\TurboC3\\BGI");              																																																																																																																			     strcpy(log[1].pass,"Allen");

    setbkcolor(0);                                           																																																																																																																				     strcpy(log[2].user,"Oliver");
    font(2,3);                                               																																																																																																																				     strcpy(log[2].pass,"Queen");

   for(int i=23;i<=25;i++)
   {
	outtextxy(50+i,200,"THIS PROGRAM IS NOT MOUSE COMPATIBLE.");
	outtextxy(60+i,230,"     INCONVENIENCE IS REGRETTED.");
   }
   delay(5000);
   cleardevice();
   load(200);

   cleardevice();
   delay(50);

   while(1)
   {
   cleardevice();
   setbkcolor(14);
   logo(4);
   font(3,9);
   setcolor(2);
   for(i=23;i<=27;i++)
   {
      setcolor(6);
      outtextxy(200+i,50,"WELCOME TO" );
      setcolor(1);
      outtextxy(110+i,100,"''THE CHICKEN CORNER''");
   }

   font(1,1);
   setcolor(1);
   outtextxy(getmaxx()-150,getmaxy()-30,"A:ADMINISTRATOR");

   font(3,9);
   setcolor(2);

   for(i=23;i<=27;i++)
   {
       outtextxy(200+i,200,"1:PLACE AN ORDER");
       outtextxy(200+i,240,"2:ABOUT US");
       outtextxy(200+i,280,"3:BRANCHES");
       outtextxy(200+i,320,"4:LEAVE A FEEDBACK");
       outtextxy(200+i,360,"5:EXIT");
   }

   i=0;
   int l=0;

   while(!kbhit())
   {
     if(l==200)
       l=1;
     font(3,6);
     for(i=23;i<=26;i++)
     {
	setcolor(3+rand());
	outtextxy(360+i,130,"IT'S AWESOME....");
     }
     font(3,9);
     delay(300);
     font(1,1);
     setcolor(14);
     outtextxy(400-((l-1)*2),400,"WE ALSO UNDERTAKE PARTY ORDERS");
     outtextxy(2,400,"WE ALSO UNDERTAKE PARTY ORDERS");
     setcolor(7);
     outtextxy(400-(l*2),400,"WE ALSO UNDERTAKE PARTY ORDERS");
     l++;

   }
   char ch=getch();
   switch(ch)
    {
	case '1':
		int i=1;
		char go='a';
		char ch2='a'	;
		char check;
		int navi;
		while(1)
		{
		   while(1)
		   {
			cleardevice();
			navi=getmaxy()/14*i;
			navigator(getmaxx()/4,navi);
			switch(i)
			{
				case 1:
					snacks();
					break;
				case 3:
					krushers();
					break;
				case 5:
					combos();
					break;
				case 7:
					fries();
					break;
				case 9:
					burgers();
					break;
				case 11:
					desserts();
					break;
				case 13:
					coke();
					break;
			}
			menutable();
			go = getch();
			if(go==72 && i==1)
			  i+=2;
			if(go==80 && i==13)
			  i-=2;
			switch(go)
			{
				case 72:
					i-=2;
					break;
				case 80:
					i+=2;
					break;
			}
		   if(go==13||go==27)
		     break;
		   if(go=='o'||go=='O')
		     break;
		   }
		if(go==27)
		  break;
		else if(go=='o'||go=='O')
		{
		 order();
		 continue;
		}
		setbkcolor(4);
		ch2=getch();
		if(ch2==27)
		  continue;
		cleardevice();
		switch(i)
		{
			case 1:
			       switch(ch2)
			       {
				   case '1':
					    draw_french();
					    e[0].display(105,50);
					    break;
				   case '2':draw_french();
					    e[1].display(105,50);
							 break;
						case '3':draw_smiles();
							 e[2].display(getmaxx()/2-75,50);
							 break;
						case '4':e[3].display(getmaxx()/2-130,50);
							 break;
						case '5':e[4].display(getmaxx()/2-140,50);
							 break;
					}
					break;

			case 3:         switch(ch2)
					{
						case '1':e[5].display(getmaxx()/2-130,50);
							 break;
						case '2':e[6].display(getmaxx()/2-185,50);
							 break;
						case '3':e[7].display(getmaxx()/2-130,50);
							 break;
						case '4':e[8].display(getmaxx()/2-175,50);
							 break;
						case '5':e[9].display(getmaxx()/2-130,50);
							 break;
						case '6':e[10].display(getmaxx()/2-210,50);
							 break;
						case '7':e[11].display(getmaxx()/2-160,50);
							 break;
						case '8':e[12].display(getmaxx()/2-160,50);
							 break;
					}
					break;

			case 5:         switch(ch2)
					{
						case '1':    	e[13].display(getmaxx()/2-130,50);
								break;
						case '2':	e[14].display(getmaxx()/2-130,50);
								break;
						case '3':	e[15].display(getmaxx()/2-130,50);
								break;
						case '4':	e[16].display(getmaxx()/2-130,50);
								break;
						case '5':	e[17].display(getmaxx()/2-130,50);
								break;
					}
					break;

			case 7:         switch(ch2)
					{
						case '1':	e[18].display(getmaxx()/2-155,50);
								break;
						case '2':	e[19].display(getmaxx()/2-155,50);
								break;
						case '3':	e[20].display(getmaxx()/2-155,50);
								break;
						case '4':	e[21].display(getmaxx()/2-150,50);
								break;
						case '5':	e[22].display(getmaxx()/2-155,50);
								break;
						case '6':	e[23].display(getmaxx()/2-145,50);
								break;
						case '7':	e[24].display(getmaxx()/2-170,50);
								break;
					}
					break;

			case 9:         switch(ch2)
					{
						case '1':	e[25].display(getmaxx()/2-145,50);
								break;
						case '2':	e[26].display(getmaxx()/2-140,50);
								break;
						case '3':	e[27].display(getmaxx()/2-150,50);
								break;
						case '4':	e[28].display(getmaxx()/2-130,50);
								break;
					}
					break;

			case 11:        switch(ch2)
					{
						case '1':       draw_icream(15,15);
								e[29].display(getmaxx()/2-90,50);
								break;
						case '2':       draw_icream(13,13);
								e[30].display(getmaxx()/2-130,50);
								break;
						case '3':       draw_icream(14,14);
								e[31].display(getmaxx()/2-80,50);
								break;
						case '4':       draw_icream(8,8);
								e[32].display(getmaxx()/2-110,50);
								break;
						case '5':       draw_icream(11,11);
								e[33].display(getmaxx()/2-55,50);
								break;
						case '6':       draw_icream(6,6);
								e[34].display(getmaxx()/2-130,50);
								break;
						case '7':       draw_icream(8,6);
								e[35].display(getmaxx()/2-115,50);
								break;
					}
					break;

			case 13:        switch(ch2)
					{
						case '1':	e[36].display(getmaxx()/2-130,50);
								break;
						case '2':       draw_coke300();
								e[37].display(getmaxx()/2-130,50);
								break;
						case '3':       if(strcmpi(e[38].dprice()," ")!=0)
								  e[38].display(getmaxx()/2-130,50);
								break;
						case '4':	if(strcmpi(e[39].dprice()," ")!=0)
								  e[39].display(getmaxx()/2-130,50);
								break;
						case '5':       if(strcmpi(e[40].dprice()," ")!=0)
								  e[40].display(getmaxx()/2-130,50);
								break;
						case '6':       if(strcmpi(e[41].dprice()," ")!=0)
								  e[41].display(getmaxx()/2-130,50);
								break;
						case '7':       if(strcmpi(e[42].dprice()," ")!=0)
								  e[42].display(getmaxx()/2-130,50);
								break;
						case '8':       if(strcmpi(e[43].dprice()," ")!=0)
								  e[43].display(getmaxx()/2-130,50);
								break;
					}
					break;
		}
		}
		break;

	case '2':
		cleardevice();
		if(atcount==0)
		  load(150);
		setbkcolor(0);
		setcolor(14);
		font(3,9);
		for(i=23; i<=26; ++i)
		  outtextxy(220+i,60,"ABOUT US");
		line(240,91,388,91);
		line(240,92,388,92);
		logo(4);
		setcolor(2);
		font(4,1);
		for(int i1=5;i1<=6;i1++)
		{
		   outtextxy(i1+60,100,"THE CHICKEN CORNER CONCEPT IS TO OFFER GREAT FOOD ");
		   outtextxy(i1+100,120,"AND BEVERAGES IN A FUN FEELING ATMOSPHERE, ");
		   outtextxy(i1+180,140,"SERVED BY FRIENDLY PEOPLE.");
		   outtextxy(i1+120,160,"WE ARE A CASUAL DINING ESTABLISHMENT");
		   outtextxy(i1+70,180,"WHERE COUPLES, FAMILIES AND FRIENDS CAN ENJOY ");
		   outtextxy(i1+30,200,"A VARIED MENU OF TASTY FRIED CHICKEN, BURGERS, POPCORNS,");
		   outtextxy(i1+130,220,"LOLLYPOPS, COMBO MEALS AND DESSERTS");
		   outtextxy(i1+50,240,"AS WELL AS A BROAD SELECTION OF KRUSHERS AND DRINKS.");
		   outtextxy(i1+80,300,"THIS REFRESHING CONCEPT EMBODIES ALL THE FUN");
		   outtextxy(i1+85,320,"AND DISTILS THAT SPIRIT INTO A WONDERFUL, CASUAL");
		   outtextxy(i1+80,340,"DINING EXPERIENCE THAT THROWS ITS DOORS OPEN");
		   outtextxy(i1+230,360,"ALL WEEK LONG.");
		}
		font(1,1);
		setcolor(10);
		++atcount;
		outtextxy(310,460,"(PRESS ANY KEY TO GET TO THE HOME SCREEN)");
		getch();
		break;

	case '3':
		while(1)
		{
		   cleardevice();
		   if(brcount == 0)
		     load(150);
		   setbkcolor(2);
		   logo(4);
		   setcolor(14);
		   font(3,9);
		   for(i=23; i<=26; ++i)
		     outtextxy(200+i,50,"BRANCHES");
		   line(220,80,370,80);
		   line(220,81,370,81);
		   font(3,6);
		   setcolor(1);
		   for(int i2=1;i2<=3;i2++)
		   {
		      outtextxy(20+i2,100,"OUR RESTAURANTS EXIST AT VARIOUS LOCATIONS THROUGHOUT THE COUNTRY.");
		      outtextxy(50+i2,120,"BY 2015 WE WILL HAVE MORE THAN 100 RESTAURANTS IN INDIA.");
		      outtextxy(160+i2,140,"THERE'S PROBABLY ONE NEAR YOU !! !!");

		   }
		   font(2,1);
		   setcolor(4);
		   for(i2=1;i2<=2;i2++)
		   {
			outtextxy(75+i2,200,"1) BANGALORE");
			outtextxy(75+i2,240,"3) COCHIN");
			outtextxy(75+i2,280,"5) KOLKATA");
			outtextxy(75+i2,320,"7) NEW DELHI");
			outtextxy(getmaxx()-225+i2,200,"2) CHENNAI");
			outtextxy(getmaxx()-225+i2,240,"4) HYDERABAD");
			outtextxy(getmaxx()-225+i2,280,"6) MUMBAI");
			outtextxy(getmaxx()-225+i2,320,"8) PUNE");
		   }
		   font(1,1);
		   setcolor(10);
		   outtextxy(380,460,"PRESS ESCAPE TO GET TO MAIN MENU");
		   setcolor(15);
		   outtextxy(85,390,"PRESS CITY NUMBER TO SEE OUR VARIOUS BRANCHES");
		   ++brcount;
		   ch=getch();
		   if(ch==27)
		     break;
		   else if(ch=='1')
		   {
			addstart();
			setbkcolor(7);
			font(4,1);
			outtextxy(275,5,"BANGALORE");
			font(3,4);
			outtextxy(110,35,"BANGALORE IS THE CAPITAL CITY OF KARNATAKA, LOCATED IN THE DECCAN PLATEAU");
			outtextxy(205,55,"IN THE SOUTH-EATERN PART OF THIS STATE.");
			outtextxy(115,75,"IT IS THE THIRD MOST POPULATED CITY AS WELL AS THE FIFTH MOST POPULOUS");
			outtextxy(235,95,"URBAN AGGLOMERATION IN INDIA.");

			outtextxy(a+60,x,"MYSORE ROAD");
			outtextxy(a+30,x+50,"WONDERLA AMUSEMENT PARK,");
			outtextxy(a+35,x+70,"MYSORE ROAD,BANGALORE,");
			outtextxy(a+65,x+90,"KARNATAKA.");
			outtextxy(a+20,x+245,"080-73828989");

			outtextxy(b+70,x,"CMH ROAD");
			outtextxy(b+47,x+50,"NO 1/1A (CMH ROAD),");
			outtextxy(b+65,x+70,"INDIRA NAGAR,");
			outtextxy(b+70,x+90,"KARNATAKA.");
			outtextxy(b+20,x+245,"080-79129469");

			outtextxy(c+56,x,"BASHVESHWAR NAGAR");
			outtextxy(c+13,x+50,"NO - 729 MODI HOSPITAL JUNCTION,");
			outtextxy(c+20,x+70,"MODI HOSPITAL ROAD 2ND STAGE,");
			outtextxy(c+20,x+90,"BASHVESHWAR NAGAR, KARNATAKA.");
			outtextxy(c+20,x+245,"080-72822839");

			font(3,5);
			outtextxy(b+24,x+220,"CONTACT NUMBER'S :-");
			outtextxy(b-145,x+300,"CORNER TIMING'S : 11:00 am to 01:30 pm <-> 02:00 pm to 10:00 pm");
			getch();
		   }
		   else if(ch=='2')
		   {
			addstart();
			setbkcolor(3);
			font(4,1);
			outtextxy(280,5,"CHENNAI");
			font(3,4);
			outtextxy(70,35,"CHENNAI WHICH WAS FORMERLY KNOWN AS 'MADRAS' IS THE CAPITAL CITY IN THE INDIAN STATE OF");
			outtextxy(125,55,"TAMIL NADU, LOCATED ON THE COROMANDEL COAST OF THE BAY OF BENGAL.");
			outtextxy(100,75,"IT IS THE BIGGEST INDUSTRIAL AND COMMERCIAL CENTER IN SOUTH INDIA AND A MAJOR");
			outtextxy(165,95,"CULTURAL, ECONOMIC AND AN EDUCATIONAL CENTER AS WELL.");

			outtextxy(a+60,x,"ASHOK NAGAR");
			outtextxy(a+18,x+50,"B-18, 100 FEET RD, 1ST AVENUE");
			outtextxy(a+30,x+70,"ASHOK NAGAR, CHENNAI-83,");
			outtextxy(a+65,x+90,"TAMIL NADU.");
			outtextxy(a+20,x+245,"044-26282022");

			outtextxy(b+60,x,"VIRUGAMBAKKAM");
			outtextxy(b+24,x+50,"CHANDRA METRO MALL, KAMBER");
			outtextxy(b+38,x+70,"STREET, VIRUGAMBAKKAM,");
			outtextxy(b+34,x+90,"CHENNAI-108, TAMIL NADU");
			outtextxy(b+20,x+245,"044-26570183");

			outtextxy(c+60,x,"MUGAPPAIR EAST");
			outtextxy(c+50,x+50,"NEAR SPARTAN SCHOOL");
			outtextxy(c+23,x+70,"PANNER NAGAR, MUGAPPAIR EAST");
			outtextxy(c+38,x+90,"CHENNAI-37, TAMIL NADU.");
			outtextxy(c+20,x+245,"044-26560018");

			font(3,5);
			outtextxy(b+24,x+220,"CONTACT NUMBER'S :-");
			outtextxy(b-145,x+300,"CORNER TIMING'S : 10:45 am to 01:00 pm <-> 01:45 pm to 10:30 pm");
			getch();
		   }
		   else if(ch=='3')
		   {
			addstart();
			setbkcolor(1);
			font(4,1);
			outtextxy(290,5,"COCHIN");
			font(3,4);
			outtextxy(120,35,"COCHIN IS A MAJOR PORT CITY, LOCATED ON THE WEST COAST OF INDIA BY THE");
			outtextxy(160,55,"ARABIAN SEA. IT IS A PART OF THE DISTRICT OF THE CITY OF");
			outtextxy(100,75,"ERNAKULUM IN THE STATE OF KERELA. KOCHI IS ALSO CALLED BY THE NAME ERNAKULUM");
			outtextxy(185,95,"WHICH REFER'S TO THE MAINLAND PART OF THE CITY.");

			outtextxy(a+80,x,"MG ROAD");
			outtextxy(a+45,x+50,"SITE NUMBER:39,2580,");
			outtextxy(a+50,x+70,"MG ROAD,COCHIN-95,");
			outtextxy(a+80,x+90,"KERALA.");
			outtextxy(a+20,x+245,"0484-2019356");

			outtextxy(b+47,x,"CENTER SQUARE MALL");
			outtextxy(b+27,x+50,"NEXT TO HOTEL ABAD PLAZA,");
			outtextxy(b+47,x+70,"MG ROAD, COCHIN-98,");
			outtextxy(b+75,x+90,"KERALA.");
			outtextxy(b+20,x+245,"0484-2946483");

			outtextxy(c+77,x,"GOLD SOUK");
			outtextxy(c+14,x+50,"GOLD SOUK GRANDE, GROUND FLOOR,");
			outtextxy(c+10,x+70,"SHOP NO:1, EDAPALLI BYPASS ROAD,");
			outtextxy(c+43,x+90,"NEAR VYTHILLA JUNCTION,");
			outtextxy(c+57,x+110,"COCHIN-50, KERALA.");
			outtextxy(c+20,x+245,"0484-2710471");

			font(3,5);
			outtextxy(b+24,x+220,"CONTACT NUMBER'S :-");
			outtextxy(b-145,x+300,"CORNER TIMING'S : 11:00 am to 01:45 pm <-> 02:00 pm to 10:20 pm");
			getch();
		   }
		   else if(ch=='4')
		   {
			addstart();
			setbkcolor(3);
			font(4,1);
			outtextxy(267,5,"HYDERABAD");
			font(3,4);
			outtextxy(80,35,"HYDERABAD IS THE CAPITAL AS WELL AS THE LARGEST CITY OF THE SOUTH INDIAN STATE OF");
			outtextxy(55,55,"ANDHRA PRADESH, OCCUPYING A TOTAL OF 650 SQUARE KILOMETER'S, ALONG THE BANK'S OF THE MUSI");
			outtextxy(150,75,"RIVER. IT HAS A POPULATION OF 6.8 MILLION AND A METROPOLITAN");
			outtextxy(40,95,"POPULATION OF 7.75 MILLION, WHICH MAKES IT THE FOURTH MOST POPULOUS CITY IN INDIAN SUBCONTINENT.");

			outtextxy(a+65,x,"CHANDANAGAR");
			outtextxy(a+60,x+50,"GROUND FLOOR, ");
			outtextxy(a+38,x+70,"OPP.TO PRAGATI COLLEGE,");
			outtextxy(a+17,x+90,"CHANDANAGAR, SHERLINGAMPALLY,");
			outtextxy(a+17,x+110,"HYDERABAD-45, ANDHRA PRADESH.");
			outtextxy(a+20,x+245,"040-83672810");

			outtextxy(b+60,x,"INORBIT MALL");
			outtextxy(b+23,x+50,"F&B 14-B FOOD COURT LEVEL,");
			outtextxy(b+34,x+70,"INORBIT MALL, MADHAPUR,");
			outtextxy(b+25,x+90,"HI-TECH CITY,HYDERABAD-30,");
			outtextxy(b+52,x+110,"ANDHRA PRADESH.");
			outtextxy(b+20,x+245,"040-88374729");

			outtextxy(c+68,x,"A.S RAO NAGAR");
			outtextxy(c+4,x+50,"SHOP NO G1, PLOT NO A-13, PNR SSV");
			outtextxy(c+12,x+70,"COMPLEX, A.S RAO NAGAR MAIN ROAD");
			outtextxy(c+65,x+90,"HYDERABAD-97,");
			outtextxy(c+60,x+110,"ANDHRA PRADESH.");
			outtextxy(c+20,x+245,"040-81272172");

			font(3,5);
			outtextxy(b+24,x+220,"CONTACT NUMBER'S :-");
			outtextxy(b-145,x+300,"CORNER TIMING'S : 10:10 am to 01:20 pm <-> 02:00 pm to 10:00 pm");
			getch();
		   }
		   else if(ch=='5')
		   {
			addstart();
			setbkcolor(5);
			font(4,1);
			outtextxy(275,5,"KOLKATA");
			font(3,4);
			outtextxy(25,35,"ALSO KNOWN BY THE NAME 'CALCUTTA' IS THE CAPITAL CITY OF THE INDIAN STATE OF WEST BENGAL, LOCATED ON");
			outtextxy(115,55,"THE EAST BANK OF THE HOOGLY RIVER. IT'S THE PRINCIPAL COMMERCIAL, CULTURAL");
			outtextxy(25,75,"AND AS WELL AS THE EDUCATIONAL CENTER OF EAST INDIA WHILE THE PORT OF THIS CITY IS THE INDIA'S MOST");
			outtextxy(150,95,"OLDEST OPERATING PORT AS WELL AS IT'S SOLE MAJOR RIVERINE PORT.");

			outtextxy(a+57,x,"CITY CENTRE MALL");
			outtextxy(a+14,x+50,"SHOP NO:105, CITY CENTRE MALL,");
			outtextxy(a+37,x+70,"SALT LAKE, KOLKATA-60,");
			outtextxy(a+65,x+90,"WEST BENGAL.");
			outtextxy(a+20,x+245,"033-69182730");

			outtextxy(b+65,x,"MANI SQUARE");
			outtextxy(b+23,x+50,"164/1,MANIKTALA MAIN ROAD,");
			outtextxy(b+11,x+70,"SHOP NO-313A, B&C, KOLKATA-54,");
			outtextxy(b+65,x+90,"WEST BENGAL.");
			outtextxy(b+20,x+245,"033-64620273");

			outtextxy(c+73,x,"QUEST MALL");
			outtextxy(c+32,x+50,"33 SAYED AMIR ALI AVENUE,");
			outtextxy(c+40,x+70,"5TH FLOOR, KOLKATA-90,");
			outtextxy(c+65,x+90,"WEST BENGAL.");
			outtextxy(c+20,x+245,"033-61028341");

			font(3,5);
			outtextxy(b+24,x+220,"CONTACT NUMBER'S :-");
			outtextxy(b-145,x+300,"CORNER TIMING'S : 10:25 am to 01:00 pm <-> 01:30 pm to 10:00 pm");
			getch();
		   }
		   else if(ch=='6')
		   {
			addstart();
			setbkcolor(4);
			font(4,1);
			outtextxy(280,5,"MUMBAI");
			font(3,4);
			outtextxy(120,35,"MUMBAI, ALSO KNOWN BY IT'S FORMER NAME 'BOMBAY', IS THE CAPITAL CITY OF");
			outtextxy(160,55,"THE STATE OF MAHARASHTRA. IT IS ONE OF THE MOST POPULATED");
			outtextxy(85,75,"CITIES IN THE INDIAN SUBCONTINENT AS WELL AS THE FOURTH MOST THAT OF IN THE WORLD,");
			outtextxy(165,95,"HAVING A TOTAL POPULATION OF APPROXIMATELY 20.5 MILLION.");

			outtextxy(a+65,x,"INFINITY MALL");
			outtextxy(a+24,x+50,"SHOP NO:TF-328, 3RD FLOOR,");
			outtextxy(a+24,x+70,"FOOD COURT, INFINITY MALL,");
			outtextxy(a+31,x+90,"LINK ROAD, MALAD (WEST),");
			outtextxy(a+34,x+110,"MUMBAI-19, MAHARASHTRA.");
			outtextxy(a+20,x+245,"022-72986269");

			outtextxy(b+40,x,"INTERNATIONAL AIRPORT");
			outtextxy(b+46,x+50,"DEPARTURE GATE-B,");
			outtextxy(b+43,x+70,"CHATRAPATI SHIVAJI");
			outtextxy(b+35,x+90,"INTERNATIONAL AIRPORT,");
			outtextxy(b+33,x+110,"MUMBAI-50, MAHARASHTRA.");
			outtextxy(b+20,x+245,"022-72019746");

			outtextxy(c+68,x,"ANDHERI WEST");
			outtextxy(c+43,x+50,"KOHLI VILLA, S.V.ROAD,");
			outtextxy(c+66,x+70,"ANDHERI WEST,");
			outtextxy(c+73,x+90,"MUMBAI-107,");
			outtextxy(c+70,x+110,"MAHARASHTRA.");
			outtextxy(c+20,x+245,"022-75282281");

			font(3,5);
			outtextxy(b+24,x+220,"CONTACT NUMBER'S :-");
			outtextxy(b-145,x+300,"CORNER TIMING'S : 10:50 am to 12:30 pm <-> 01:00 pm to 10:15 pm");
			getch();
		   }
		   else if(ch=='7')
		   {
			addstart();
			setbkcolor(0);
			font(4,1);
			outtextxy(265,5,"NEW DELHI");
			font(3,4);
			outtextxy(90,35,"DELHI, ALSO KNOWN AS THE NATIONAL CAPITAL TERRITORY OF INDIA, IS THE METROPOLITAN");
			outtextxy(170,55,"REGION IN INDIA, WITH A TOTAL POPULATION OF 22 MILLION");
			outtextxy(120,75,"AS ESTIMATED IN 2011. IT'S THE WORLD'S SECOND MOST POPULOUS CITY AND THE");
			outtextxy(205,95,"LARGEST CITY IN INDIA IN TERM'S OF AREA.");

			outtextxy(a+60,x,"SHIPRA MALL");
			outtextxy(a+20,x+50,"SHOP NO-19, GP SHIPRA MALL,");
			outtextxy(a+25,x+70,"NH-24, VASUNTHRA ENACLAVE");
			outtextxy(a+24,x+90,"INDRAPURAM, NEW DELHI-110.");
			outtextxy(a+20,x+245,"011-24628701");

			outtextxy(b+60,x,"SUNCITY MALL");
			outtextxy(b+15,x+50,"SHOP NO-12,13, GROUND FLOOR,");
			outtextxy(b+40,x+70,"VASANT SQUARE MALL,");
			outtextxy(b+23,x+90,"VASANT KUNJ, NEW DELHI-67.");
			outtextxy(b+20,x+245,"011-65289195");

			outtextxy(c+65,x,"NEHRU PLACE");
			outtextxy(c+11,x+50,"FOOD COURT, LOWER GROUND FLOOR,");
			outtextxy(c+38,x+70,"TDI MALL, NEHRU PLACE,");
			outtextxy(c+23,x+90,"METRO STATION, NEW DELHI-75.");
			outtextxy(c+20,x+245,"011-98342671");

			font(3,5);
			outtextxy(b+24,x+220,"CONTACT NUMBER'S :-");
			outtextxy(b-145,x+300,"CORNER TIMING'S : 10:30 am to 01:40 pm <-> 02:15 pm to 11:00 pm");
			getch();
		   }
		   else if(ch=='8')
		   {
			addstart();
			setbkcolor(2);
			font(4,1);
			outtextxy(285,5,"PUNE");
			font(3,4);
			outtextxy(160,35,"PUNE IS THE EIGHTH LARGEST METROPOLIS IN INDIA AS WELL AS");
			outtextxy(110,55,"THE SECOND LARGEST OF THAT IN THE INDIAN STATE OF MAHARASHTRA. IT IS LOCATED");
			outtextxy(160,75,"AT THE HEIGHT OF 560 m (1,837 FEET) ABOVE THE SEA LEVEL,");
			outtextxy(130,95,"ON THE RIGHT HAND SIDE BANK OF THE MUTHA RIVER, IN THE DECCAN PLATEAU.");

			outtextxy(a+45,x,"GOREGAON PARK PLAZA");
			outtextxy(a+30,x+50,"UNIT K7+K8, SECOND FLOOR,");
			outtextxy(a+38,x+70,"GOREGAON PARK PLAZA,");
			outtextxy(a+55,x+90,"NORTH MAIN ROAD,");
			outtextxy(a+42,x+110,"NEXT TO WESTIN HOTEL,");
			outtextxy(a+45,x+130,"NEAR VINAYAK FARMS,");
			outtextxy(a+39,x+150,"PUNE-60, MAHARASHTRA.");
			outtextxy(a+20,x+245,"020-45928763");

			outtextxy(b+60,x,"KALYANI NAGAR");
			outtextxy(b-2,x+50,"MARIPLEX, SURVEY NO:15/1,15/2,15/5,");
			outtextxy(b+15,x+70,"VADGAON SHERI, KALYANI NAGAR,");
			outtextxy(b+39,x+90,"PUNE-50, MAHARASHTRA.");
			outtextxy(b+20,x+245,"020-23453425");

			outtextxy(c+70,x,"PACIFIC MALL");
			outtextxy(c+2,x+50,"UNIT NOS.08-09, KUMAR PACIFIC MALL,");
			outtextxy(c+12,x+70,"CTS NO 42&43, SHANKARSETH ROAD,");
			outtextxy(c+10,x+90,"GULTEKDI, PUNE-101, MAHARASHTRA.");
			outtextxy(c+20,x+245,"020-28796955");

			font(3,5);
			outtextxy(b+24,x+220,"CONTACT NUMBER'S :-");
			outtextxy(b-145,x+300,"CORNER TIMING'S : 10:10 am to 01:30 pm <-> 02:10 pm to 10:45 pm");
			getch();
		   }
		   }
		   break;

	case '4':
		cleardevice();
		//load(100);
		setbkcolor(15);
		font(3,9);
		logo(4);
		for(int i4=23;i4<=27;i4++)
		{
		   outtextxy(90+i4,135,"FEEDBACK / SUGGESTION");
		   outtextxy(getmaxx()/2-100+i4,185,"CENTRE");
		}
		for(i4=0;i4<=1;i4++)
		{
		   line(111,168+i4,488,168+i4);
		   line(245,218+i4,350,218+i4);
		}
		font(1,1);
		outtextxy(250,460,"(PRESS TAB KEY TO SEE OUR VALUABLE FEEDBACKS)");
		outtextxy(50,255,"NAME :");
		line(50,264,80,264);
		outtextxy(20,303,"PHONE NO : ");
		line(20,312,82,312);
		outtextxy(20,353,"FEEDBACK : ");
		line(20,362,82,362);
		setcolor(6);
		for(i4=0;i4<2;i4++)
		{
		   rectangle(100+i4,250+i4,500+i4,270+i4);
		   rectangle(100+i4,300+i4,250+i4,320+i4);
		   rectangle(100+i4,350+i4,500+i4,390+i4);
		}
		marker(629,460,2);
		setcolor(15);
		char ch10 = getch();
		if(ch10 != 9)
		{
		  setcolor(0);
		  int hide[10]={0,getmaxy()-50,getmaxx(),getmaxy()-50,getmaxx(),getmaxy(),0,getmaxy()};
		  setfillstyle(1,0);
		  fillpoly(4,hide);
		  marker(515,260,2);
		  accept();
		  fstream f("Feed.dat",ios::out|ios::app|ios::binary);
		  f.write((char*)&feed,sizeof(feed));
		  f.close();
		  cleardevice();
		  setbkcolor(0);
		  setcolor(15);
		  font(2,3);
		  for(i4=0;i4<=2;i4++)
		  {
		     outtextxy(200+i4,50,"YOUR FEEDBACK");
		     outtextxy(200+i4,90,"HAS BEEN SUBMITTED");
		     outtextxy(200+i4,130,"SUCCESSFULLY");
		     outtextxy(200+i4,230,"THANK YOU");
		     outtextxy(200+i4,270,"FOR SPENDING");
		     outtextxy(200+i4,310,"YOUR TIME");
		     outtextxy(200+i4,350,"WITH US");
		  }
		  delay(5000);
		}
		else if (ch10 == 9)
		{
		  cleardevice();
		  setbkcolor(6);
		  for(int h=0;h<=getmaxy()-3;h+=getmaxy()/5)
		  {
		     line(0,h+1,getmaxx(),h+1);
		     line(0,h+2,getmaxx(),h+2);
		     line(0,h+3,getmaxx(),h+3);
		  }
		  font(3,6);
		  dispfeed();
		  getch();
		}
		break;

	case 'a':
		cleardevice();
		setbkcolor(0);
		font(2,4);
		setcolor(4);
		outtextxy(200,50,"ADMINISTRATOR");
		outtextxy(250,100,"DETAILS");
		for(int u=0;u<=1;u++)
		{
		   line(200,88+u,433,88+u);
		   line(250,138+u,367,138+u);
		}
		font(10,1);
		setcolor(15);
		rectangle(100,getmaxy()/2-30,200,getmaxy()/2-10);
		rectangle(100,getmaxy()/2+20,200,getmaxy()/2+40);
		setcolor(2);
		outtextxy(18,getmaxy()/2-25,"ADMIN NAME");
		outtextxy(25,getmaxy()/2+25,"PASSWORD");
		feedbk(log[3].user,getmaxy()/2-25,10);
		password(log[3].pass,getmaxy()/2+25);
		if(!strcmp(log[3].user,log[0].user)&&!strcmp(log[3].pass,log[0].pass)||(log[3].user,log[1].user)&&!strcmp(log[3].pass,log[1].pass)||(log[3].user,log[2].user)&&!strcmp(log[3].pass,log[2].pass))
		{
		  outtextxy(getmaxx()/2-60,getmaxy()-100,"WELCOME USER....");
		  delay(2000);
		  cleardevice();
		  font(1,1);
		  cleardevice();
		  char get;
		  do
		  {
		    for(int qw=0;qw<2;qw++)
		    {
		       font(3,9);
		       outtextxy(100+qw,100,"WHAT WOULD YOU LIKE TO DO ??");
		       font(3,7);
		       outtextxy(200+qw,200,"1.CREATE A NEW ITEM");
		       outtextxy(200+qw,225,"2.ALTER ITEM DETAILS");
		       outtextxy(200+qw,250,"3.VIEW CUSTOMER DETAILS");
		       outtextxy(200+qw,275,"4.EXIT");
		    }
		    get=getch();
		  }while(get!='1'&&get!='2'&&get!='3'&&get!='4');
		  cleardevice();
		  if(get=='2')
		  {
		    font(1,1);
		    outtextxy(200,20,"LIST OF ITEMS");
		    for(int i3=1;i3<=26;i3++)
		    {
		       char s[3]={i3+96,')','\0'};
		       outtextxy(70,50+15*i3,s);
		       char name[20];
		       strcpy(name,e[i3-1].dname1());strcat(name," ");
		       strcat(name,e[i3-1].dname2());strcat(name," ");
		       strcat(name,e[i3-1].dname3());
		       outtextxy(85,50+15*i3,name);
		    }
		    int a=i3,x=11;
		    if(strcmp(e[38].dprice()," ")!=0)
		      x=12;
		    if(strcmp(e[39].dprice()," ")!=0)
		      x=13;
		    if(strcmp(e[40].dprice()," ")!=0)
		      x=14;
		    if(strcmp(e[41].dprice()," ")!=0)
		      x=15;
		    if(strcmp(e[42].dprice()," ")!=0)
		      x=16;
		    if(strcmp(e[43].dprice()," ")!=0)
		      x=17;
		    for(i3=1;i3<=x;i3++,++a)
		    {
		       char s[3]={i3+64,')','\0'};
		       outtextxy(400,50+15*i3,s);
		       char name[20];
		       strcpy(name,e[a].dname1());strcat(name," ");
		       strcat(name,e[a].dname2());strcat(name," ");
		       strcat(name,e[a].dname3());
		       outtextxy(415,50+15*i3,name);
		    }
		    int itemno;
		    while(1)
		    {
		    outtextxy(300,400,"WHICH ITEM WOULD YOU LIKE TO ALTER ?");
		    char item1=getch();
		    if(item1>='a'&&item1<='z')
		    {
		      itemno=item1-97;
		      break;
		    }
		    else if(item1>='A'&&item1<=64+x)
		    {
		      itemno=item1-38;
		      break;
		    }
		    else
		      continue;
		    }
		    do
		    {
		      cleardevice();
		      font(1,1);
		      char name[50];
		      strcpy(name,"YOU HAVE SELECTED ");
		      strcat(name,e[itemno].dname1());strcat(name," ");
		      strcat(name,e[itemno].dname2());strcat(name," ");
		      strcat(name,e[itemno].dname3());
		      outtextxy(100,50,name);
		      outtextxy(100,100,"WHAT WOULD YOU LIKE TO ALTER ?");
		      outtextxy(100,125,"1) 1ST NAME");
		      outtextxy(100,140,"2) 2ND NAME");
		      outtextxy(100,155,"3) 3RD NAME");
		      outtextxy(100,170,"4) STOCK");
		      outtextxy(100,185,"5) PRICE");
		      get=getch();
		    }while(get!='1'&&get!='2'&&get!='3'&&get!='4'&&get!='5');
		    switch(get)
		    {
			 case '1': e[itemno].cname1();break;
			 case '2': e[itemno].cname2();break;
			 case '3': e[itemno].cname3();break;
			 case '4': e[itemno].cstock();break;
			 case '5': e[itemno].cprice();break;
		    }
		  }
		  else if(get=='1')
		  {
		       font(1,1);
		       cleardevice();
		       char p1[4],n1[15],n2[10],n3[10],f1[58],f2[58],t[2],s[3];
		       int p,st,type;
		       for(i4=0;i4<2;i4++)
		       {
			  rectangle(100+i4,95+i4,500+i4,115+i4);
			  rectangle(100+i4,120+i4,250+i4,140+i4);
			  rectangle(100+i4,145+i4,500+i4,165+i4);
			  rectangle(100+i4,170+i4,500+i4,190+i4);
			  rectangle(100+i4,195+i4,500+i4,215+i4);
			  rectangle(100+i4,220+i4,500+i4,240+i4);
			  rectangle(100+i4,245+i4,500+i4,265+i4);
			  rectangle(100+i4,270+i4,500+i4,290+i4);
		       }
		       outtextxy(2,100,"ENTER NAME 1");
		       outtextxy(2,125,"ENTER NAME 2");
		       outtextxy(2,150,"ENTER NAME 3");
		       outtextxy(2,175,"ENTER INFO 1");
		       outtextxy(2,200,"ENTER INFO 2");
		       outtextxy(2,225,"ENTER PRICE");
		       outtextxy(2,250,"ENTER TYPE");
		       outtextxy(2,275,"ENTER STOCK");
		       feedbk(n1,100,15);
		       feedbk(n2,125,15);
		       feedbk(n3,150,10);
		       feedbk(f1,175,58);
		       feedbk(f2,200,58);
		       feedbk(p1,225,4);
		       feedbk(t,250,2);
		       feedbk(s,275,3);
		       strupr(n1);
		       strupr(n2);
		       strupr(n3);
		       strupr(f1);
		       strupr(f2);
		       st=atoi(s);p=atoi(p1);
		       if(strcmp(e[38].dprice()," ")==0)
			 e[38].create(t[0],p,st,f1,f2,p1,n1,n2,n3);
		       else if(strcmp(e[39].dprice()," ")==0)
			 e[39].create(t[0],p,st,f1,f2,p1,n1,n2,n3);
		       else if(strcmp(e[40].dprice()," ")==0)
			 e[40].create(t[0],p,st,f1,f2,p1,n1,n2,n3);
		       else if(strcmp(e[41].dprice()," ")==0)
			 e[41].create(t[0],p,st,f1,f2,p1,n1,n2,n3);
		       else if(strcmp(e[42].dprice()," ")==0)
			 e[42].create(t[0],p,st,f1,f2,p1,n1,n2,n3);
		       else if(strcmp(e[43].dprice()," ")==0)
			 e[43].create(t[0],p,st,f1,f2,p1,n1,n2,n3);
		  }
		  else if(get=='3')
		  {
		     dispcust();
		     getch();
		  }
		  else if(get=='4')
		     break;
		}
		else
		{
		  outtextxy(getmaxx()/2-30,getmaxy()-100,"Haha.. Nice Try....");
		  delay(2000);
		}
		break;

	case '5':
		cleardevice();
		setbkcolor(4);
		setcolor(-1);
		for(int a=0;a<=2;a++)
		{
		   settextstyle(5,HORIZ_DIR,4);
		   outtextxy(40+a,getmaxy()/3-20,"COME BACK SOON");
		   outtextxy(280+a,getmaxy()/3*2,"     THANK YOU");
		   settextstyle(5,VERT_DIR,4);
		   outtextxy(40,getmaxy()/2-50+a,"     THANK YOU");
		   outtextxy(580,getmaxy()/6+a,"COME BACK SOON");
		}
		delay(4000);
		y=0;
		fstream f2("Temp.dat",ios::out);
		while(y<=44)
		{
		   m1=e[y++];
		   f2.write((char*)&m1,sizeof(m1));
		}
		ff.close();f2.close();
		remove("Food.dat");
		rename("Temp.dat","Food.dat");
		closegraph();
		exit(0);
		break;

	default:
		break;
     }
    }
   }
