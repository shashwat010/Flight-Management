#include<iostream>
#include<string>
using namespace std;

int lpayment(string origin ,string destination){	
if((origin=="LUCKNOW" || origin=="DELHI") && (destination=="LUCKNOW" || destination=="DELHI"))
	return  4312;
if((origin=="LUCKNOW"|| origin=="CHANDIGARH") && (destination=="LUCKNOW" || destination=="CHANDIGARH"))
	return  4733;
if((origin=="BANGLORE" || origin=="CHENNAI") && (destination=="BANGLORE" || destination=="CHENNAI"))
	return  3498;
if((origin=="LUCKNOW" || origin=="BANGLORE") && (destination=="LUCKNOW" || destination=="BANGLORE"))
	return  7462;
if((origin=="LUCKNOW"|| origin=="CHENNAI") && (destination=="LUCKNOW" || destination=="CHENNAI"))
	return  7462;
if((origin=="DELHI"|| origin=="CHANDIGARH") && (destination=="DELHI" || destination=="CHANDIGARH"))
	return  3435;
if((origin=="DELHI" || origin=="BANGLORE") && (destination=="DELHI" || destination=="BANGLORE"))
	return  7422;
if((origin=="DELHI" || origin=="CHENNAI") && (destination=="DELHI" || destination=="CHENNAI"))
	return  7425;
if((origin=="CHANDIGARH" || origin=="BANGLORE") && (destination=="CHANDIGARH" ||  destination=="BANGLORE"))
	return  9445;
if((origin=="CHANDIGARH" || origin=="CHENNAI") && (destination=="CHANDIGARH" || destination=="CHENNAI"))
	return  8051;
return 0;
}

int ipayment(string origin,string destination){	
if((origin=="LONDON" || origin=="BERLIN") && (destination=="LONDON" || destination=="BERLIN"))
	        return  17049;
if((origin=="LONDON" || origin=="DUBAI") && (destination=="LONDON"|| destination=="DUBAI"))
	        return  24112;
if((origin=="LONDON" || origin=="RIYADH") && (destination=="LONDON" || destination=="RIYADH"))
	        return  48345;
if((origin=="LONDON" || origin=="BEIJING") && (destination=="LONDON" || destination=="BEIJING"))
	        return  70568;
if((origin=="LONDON" || origin=="PARIS") && (destination=="LONDON" || destination=="PARIS"))
	        return  11645;
if((origin=="LONDON" || origin=="CANBERRA") && (destination=="LONDON" || destination=="CANBERRA"))
	        return  100931;
if((origin=="LONDON" || origin=="TOKYO") && (destination=="LONDON" || destination=="TOKYO"))
	        return  47831;
if((origin=="LONDON" || origin=="WASHINGTON") && (destination=="LONDON" || destination=="WASHINGTON"))
	        return  39271;
if((origin=="LONDON" || origin=="DELHI") && (destination=="LONDON" || destination=="DELHI"))
	        return  47692;
if((origin=="LONDON" || origin=="CANADA") && (destination=="LONDON" || destination=="CANADA"))
	        return  29530;
if((origin=="BERLIN" || origin=="DUBAI") && (destination=="BERLIN" || destination=="DUBAI"))
	        return  35067;
if((origin=="BERLIN" || origin=="RIYADH") && (destination=="BERLIN" || destination=="RIYADH"))
	        return  66964;
if((origin=="BERLIN" || origin=="BEIJING") && (destination=="BERLIN" || destination=="BEIJING"))
	        return  62527;
if((origin=="BERLIN" || origin=="PARIS") && (destination=="BERLIN" || destination=="PARIS"))
	        return  4436;
if((origin=="BERLIN" || origin=="CANBERRA") && (destination=="BERLIN" || destination=="CANBERRA"))
	        return  157902;
if((origin=="BERLIN" || origin=="TOKYO") && (destination=="BERLIN" || destination=="TOKYO"))
	        return  66270;
if((origin=="BERLIN" || origin=="WASHINGTON") && (destination=="BERLIN" || destination=="WASHINGTON"))
	        return  131334;
if((origin=="BERLIN" || origin=="DELHI") && (destination=="BERLIN" || destination=="DELHI"))
	        return  36307;
if((origin=="BERLIN" || origin=="CANADA") && (destination=="BERLIN" || destination=="CANADA"))
	        return  32996;
if((origin=="DUBAI" || origin=="RIYADH") && (destination=="DUBAI" || destination=="RIYADH"))
	        return  16354;
if((origin=="DUBAI" || origin=="BEIJING") && (destination=="DUBAI" || destination=="BEIJING"))
	        return  40225;
if((origin=="DUBAI" || origin=="PARIS") && (destination=="DUBAI" || destination=="PARIS"))
	        return  26104;
if((origin=="DUBAI" || origin=="CANBERRA") && (destination=="DUBAI" || destination=="CANBERRA"))
	        return  187259;
if((origin=="DUBAI" || origin=="TOKYO") && (destination=="DUBAI" || destination=="TOKYO"))
	        return  67242;
if((origin=="DUBAI" || origin=="WASHINGTON") && (destination=="DUBAI" || destination=="WASHINGTON"))
	        return  208149;
if((origin=="DUBAI" || origin=="DELHI") && (destination=="DUBAI" || destination=="DELHI"))
	        return  527;
if((origin=="DUBAI" || origin=="CANADA") && (destination=="DUBAI" || destination=="CANADA"))
	        return  14939;
if((origin=="RIYADH" || origin=="BEIJING") && (destination=="RIYADH" || destination=="BEIJING"))
	        return  92061;
if((origin=="RIYADH" || origin=="PARIS") && ( destination=="RIYADH" || destination=="PARIS"))
	        return  51282;
if((origin=="RIYADH" || origin=="CANBERRA") && ( destination=="RIYADH" || destination=="CANBERRA"))
	        return  156525;
if((origin=="RIYADH" || origin=="TOKYO") && ( destination=="RIYADH" || destination=="TOKYO"))
	        return  110079;
if((origin=="RIYADH" || origin=="WASHINGTON") && ( destination=="RIYADH" || destination=="WASHINGTON"))
	        return  86516;
if((origin=="RIYADH" || origin=="DELHI") && ( destination=="RIYADH" || destination=="DELHI"))
	        return  723;
if((origin=="RIYADH" || origin=="CANADA") && ( destination=="RIYADH" || destination=="CANADA"))
	        return  40312;
if((origin=="BEIJING" || origin=="PARIS") && ( destination=="BEIJING" || destination=="PARIS"))
	        return  31748;
if((origin=="BEIJING" || origin=="CANBERRA") && ( destination=="BEIJING" || destination=="CANBERRA"))
	        return  86516;
if((origin=="BEIJING" || origin=="TOKYO") && ( destination=="BEIJING" || destination=="TOKYO"))
	        return  32342;
if((origin=="BEIJING" || origin=="WASHINGTON") && ( destination=="BEIJING" || destination=="WASHINGTON"))
	        return  82127;
if((origin=="BEIJING" || origin=="DELHI") && ( destination=="BEIJING" || destination=="DELHI"))
	        return  46897;
if((origin=="BEIJING" || origin=="CANADA") && ( destination=="BEIJING" || destination=="CANADA"))
	        return  73810;
if((origin=="PARIS" || origin=="CANBERRA") && ( destination=="PARIS" || destination=="CANBERRA"))
	        return  151674;
if((origin=="PARIS" || origin=="TOKYO") && ( destination=="PARIS" || destination=="TOKYO"))
	        return  39790;
if((origin=="PARIS" || origin=="WASHINGTON") && ( destination=="PARIS" || destination=="WASHINGTON"))
	        return  53712;
if((origin=="PARIS" || origin=="DELHI") && ( destination=="PARIS" || destination=="DELHI"))
	        return  35492;
if((origin=="PARIS" || origin=="CANADA") && ( destination=="PARIS" || destination=="CANADA"))
	        return  64964;
if((origin=="CANBERRA" || origin=="TOKYO") && ( destination=="CANBERRA" || destination=="TOKYO"))
	        return  91714;
if((origin=="CANBERRA" || origin=="WASHINGTON") && ( destination=="CANBERRA" || destination=="WASHINGTON"))
	        return  159865;
if((origin=="CANBERRA" || origin=="DELHI") && ( destination=="CANBERRA" || destination=="DELHI"))
	        return  113777;
if((origin=="CANBERRA" || origin=="CANADA") && ( destination=="CANBERRA" || destination=="CANADA"))
	        return  140229;
if((origin=="TOKYO" || origin=="WASHINGTON") && ( destination=="TOKYO" || destination=="WASHINGTON"))
	        return  74734;
if((origin=="TOKYO" || origin=="DELHI") && ( destination=="TOKYO" || destination=="DELHI"))
	        return  30199;
if((origin=="TOKYO" || origin=="CANADA") && ( destination=="TOKYO" || destination=="CANADA"))
	        return  124022;
if((origin=="WASHINGTON" || origin=="DELHI") && ( destination=="WASHINGTON" || destination=="DELHI"))
	        return  63761;
if((origin=="WASHINGTON" || origin=="CANADA") && ( destination=="WASHINGTON" || destination=="CANADA"))
	        return  103989;
if((origin=="DELHI" || origin=="CANADA") && ( destination=="DELHI" || destination=="CANADA"))
	        return  36096;
return 0;
}
