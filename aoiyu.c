#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_aoiyu.h"
#include <stdlib.h>
#include <string.h>

ZEND_GET_MODULE(aoiyu);

zend_function_entry aoiyu_functions[] = {
	PHP_FE(aoiyu_awesome, NULL)
	{NULL, NULL, NULL}
};

PHP_MINFO_FUNCTION(aoiyu) {
    printf("why are you even here?\n");
}

zend_module_entry aoiyu_module_entry = {
	STANDARD_MODULE_HEADER,
	"aoiyu",
	aoiyu_functions,
 	NULL,
 	NULL,
 	NULL,
 	NULL,
 	PHP_MINFO(aoiyu),
 	"1.1",
	STANDARD_MODULE_PROPERTIES,
};

#define NUM_ROW 125

static char *aoiyu_image[NUM_ROW] = {
"7I??$777$I??+?++?$=+I77I+???$?+Z7++++7=++++++7O++++?+++++?++++?+I++++=???Z77++???7I???+II777777II???I????????I?$?III7777",
"???77$7++?+++++III$IIZ$Z+?+~+?=I$+++?+?++?+?~+7=+?++7$$??7=++=+I?++++???I=7+??++$I$II??+???+$I$I+I??I???????IZ???777I?7I",
"++$$$I?????+??II+=I?I+=$II$7I777I++I?7??++++$7$$$?++I$7$777+?77+++++7I?I++?+?+++???$???$+???++?I7I?I???????+7I+7IIIIIZII",
"77Z????+$??+?+++IZ?++?+7+I+$7O7$7=??$77+++?77777?$I=I$I7777I?7=++??$$+?+++???+7?II?7I+I???7++?ZZ7I$IO??+??+II??IIII?7I7$",
"Z$+I?+?+??+?I7+?=++??ZI$==O=++=+I+=$$777++=7=$I??III?II+?+I.~O::::,::?++??++I??++I$7$$7+?+I7+7I7$I$++?????$=O$$OI7$ZI7I7",
"7Z7$7?II7I7$7++??$$Z++$=8+?+I7+?I?++$Z7Z+O?$+?+?+I=,+.:.::::,:,,,,:,,,:,::~?II+7?+=++??+??????????+I????ZI7Z$Z7II77?II$7",
"??????????+$Z++I~7?I+?IZ?+=++?+Z+?++++7=I$+?++?I:.,.+:,.:::::,,,,,..,..~::~~:~Z$=?+7??++???????????Z?$I7+I$$I7II$?7?II77",
"?????+??++7$7??ZI?+?+I++=?7=+++=+$???+???$II?..?.,:,,:,,::,,,,:,.:.,,...:,..,,:~~Z8+++???+++??+?+??$?OI+$$8IIIOI77$77777",
"??????+777?+$7+?+?O++7?=++++?+?++?+O?+?+.7Z.=,?,~:,~~~=~=,,,.,,..,:,,,,.:::.,,.I+?I+??I+????=I?Z+IZI$I$7$?$OII+7Z8$?7IO$",
"Z$$777$$7?+Z??8++7+++$++++++?=++?++I?Z?,+,,.:......,,,,~~.~,,.,.:,~,..,~:,::,,7+?~$??$7$7II????+$???II??IIIZ$ZO$$7$7Z$$Z",
"7$$777ZI???+?$??++++?I+++?+++??+++++?+...?.~..,........,,.,:~.~=..~.::,~==.,7?~~==~7$$I+?+Z7$I7$7IIII$$$OZ??III+$$7$I7Z$",
"?+$$77+?????=I???++??Z??+++?++=??+??++7~?=~,,.....    . ..~:::.,:,:...,.,~~I~?:~I?~7+?????+OI???????????I?I??$$??8O$ZZZO",
"7??I$Z??????I+???+?+O$Z+??+?+?I++??++?~=..:....~ZNMD$.......:~:,,..,==.:.:,~=,+I,~?II??IIII?+77+I???II???I7OO7$7$ZD88OOI",
"??????I+???ZI????+?=7I+=++??+++Z7Z$?++..77:+D8D8O8DD8DDDO......,,..=,..:=~=+=+.I?7I?7III77I7ZOI7I77+$7I???IIIIIIIZ7OOOI7",
"77$$Z$+???7I$??+??+I+++?+?+?+++77=+7$,==:~.NNMDD8NDOO88DNNM..  .....=.,..:=+~=+?+:?+O7$7$II7I7I$7?+I???I?IIIII?O+I8$7$7Z",
"$I7$I?+?+=I?7??????7?+++$?++???+I$$7$.O..ZMMMNNDDND88O888DDDM........+..,.=~:.===Z?7$$7IIIII?I$ZZ???I??I????ZII$78OZ77I8",
"OI+II???$ZI$7???++O$++???Z+++?++=$Z$ZZ~~:NMMMMOMMMZZN8O?DD8DD8.....,...,...=,I?$:.?ZOI???I?ZII?II???I?I??I?I?7I7II$Z8II7",
"7???7Z7IZO77I++??77$?++?+IO$????=Z$$:.~=ZMMMMZMMMN?MZ7+IOO7DNDN.....,.~.?,.,$?I?I+~+7IIIIII7OOIII??II??????Z7?IIII87II77",
"7$II????+?77$???$?77???+??7II+?+$7?$Z~Z7MMMDOZDN8?MIZD=?DOI$NMM8=,..:,.....:I+?I?+.I777III??IO$778OZZ??O$OIIIIIIII?7$I77",
"77IIII7????$$??$8777?+?++$I7Z7I?Z?=??777MM$7I?+?++==~+=+ZO+?+DMMMN,,.,==:,,?~=?I7=DI7777IIIZ?IO$$7?I77IZ7IIIIIIII8?I$I77",
"??+7$Z??I???Z+$77Z7II7+??I?I?+7????I??+IMM$I??++?++====~=+~~?+?MMM.....$+I?~+=7IZ$D$7$7IZZ777IIIZZZZZI7?IIIIIIIII$77II77",
"I??????+7$??Z?O777IOO7??D+?II7???7II?IIIMMO7I??++++?$OOOO77$7++IMM.,~.=.:=I++?I+Z=8Z87$DZ$$I77I$$Z$Z77?III77IIIII77I87I7",
"7I????I?????I7$7$Z7ZZI7?I+II$I?II7III7IIMMDNNN$I???77$I?++=+???+IMMM.....~~++??I77O7$$$77IOZ$7Z?7+??++$IIIIII7I8I77ZZZ77",
"IIIIIIII?I??I77O$O8$$7Z$7$Z$?III$7III7IIMMZ77$ZZ7III7II?Z7+I?+?+++MN..Z..N~:+??7IZI+Z$77777ZZ7$Z$III77??II?IIOI$Z7I7ZZ$7",
"$Z7I????I???$?I$Z$$7?I87$7Z?I?I?777I7777NMMNOM7$$I??77N+?OND$I+====7..I??8ZI+?I$$7I+$ZZ$Z7Z7?ZO$7I?III7IIIII$II7IZ7DZZO7",
"I?IIIII?I?7??$I?II?I?$$$Z77II?I77$77I777IMD8Z7=?7=,~===Z+?~=~~~~==+$,.N::8Z8~++?$I+ZZZZ77OOOO7$$Z777$OZ?8OI7I$$77I778O77",
"I??IIII?7?II7???IIII?7$$?$O7?III7ZI777777N7$$7?++:,::+???+=~~~~=++?7.MMZ.O$$+==I7=+8OO$$$IZO77I8Z7Z77?Z7O?O77777Z7I7$$$7",
"?IIIIIOI?I?IIIIZI7$I7$7$7IIII7II7IO7777$8Z7I?++I~::~:~=++=~~~==++?I8MMDM~$$78+ID~?7+ZZ$$$7$777Z7OZ77II7IIII$78IZ$I778OO8",
"I?IIIZIII??I?II7??$7?I+$7$??Z?7$7OI7777777ZI?++?~:~~========++??II7DOND8~7ZDO=+$$??~NZOZ$777Z7I$7IIII7I7I77I77I$77$78ID$",
"III77IIIIIIIIIO$I??77IIII?II7OI77$7O7$$$7=+7??I+~:~==?+++++++?IIII7$OZ8Z?MD7$==D88OZO8O$$$77$$7O+Z77I78ZI7I77I77II$7$INI",
"77IIIIIIIIII7?IIII7I$?I?IIIII7D$77I7$$7$$~~$7I$$II+=+7??++????IIIII7Z$O?8MZ+7+?~DDDNOD$$$$$$$7OZ$$ZZ7ZI$77I777777I77I788",
"I$77IIIII??I?IIIIII$?I$OII?7I77I77$$DO$OZZO$Z77OMN88O?=????IIIII?I77$ZZ:Z$I?I=I~8ND88Z$Z$$$7ZZ7I77I777II777II77II$OZ$8OD",
"I7ZIIIIII7III$I7II?II$7IIIII7Z77Z777$7Z8$$Z+O$7ZZ$I+====???????III7$Z$:ZZI++?,~8DD8DDZZ$8Z8$7777777I7IZZZZD$7$77I7778Z8O",
"77+IIIII8I$IIIII+OII777IIII77I$7777777877Z$~$ZZOZ$77+=++???????II7$$Z7~$O?==~,NDDDD8DO87$$7777IZ77$7IO$Z$7I77I777$I$8$OZ",
"77IIIIIZ7OZ$8?$IZIII7IIIII7I7$7777$$$$7OO8D==ZZONNNNNNNN7I??III77$$Z77:~8=~.DNDNDD88DOZ$$77O$$7$777?$Z8777777777$7$I$$Z$",
"?$IIII7O$I$$7?7IIII777I77II777O$87ZZ$$$Z8O$8++O$Z$$$77??IIIIII77$ZZ$7I~,:~~MDDMNDDDNDO8$ZZ$Z$$$$DI$$8I777I7$7$$77$DD$Z$$",
"8IOZ7IZZZ8IOI7$O7I777IZ?III77I$$$877$$7$ZNOZ~?8OO8D8O7???III77$ZZO$77I+..:?MMMMDNNDZMOO8O7$7$$O$I$7Z777I77I7II$ZZI7$$7$N",
"Z77I77O8IIII77Z$7I7I?Z$$II777IO87ZZ$$$$ZZ$NZ+?OOO7I?+++?II77$ZOO8Z$III,,:+IMDNDDNDDDDZ$$$$7$$$77$OO$I7ZZI$7OZOOI77$$O$$I",
"ZO7Z7$7Z7IIIOZZ$7II?OZ7$7I7I7$D8ZZ88$$$$$ZZN=?O8DZ7II???I7$Z88DZZ$7II~::.DDMDNMD888D8ZZZ$ZZ7777777I77777777778O7$$7O$7$O",
"7IIII7I?IZIZ7$7$$+ZZ$Z$ZII77ZOZ8O$ZZZ$$$ZZZ~:$7ONMZZZ$7$D888D88Z$$7I:.DOOOOODD8D88OODZ$Z$$$$77$777777777777O8O77$8O$Z$$8",
"$ZZ$OZ?II7II7$$Z$$$DO$8IO$$8Z7ZO7$O$7$Z$ZZZ,:O788DDDNMMMDDDDD8O$7I7..8?II77$ND8D8OO8DOZZ8D$7$77777777777787$I?7O$D$$7$$D",
"77III7I77I?7OI?ZOO8O$$$ZZDOOI7787$OZ$787ZZZ8=O$DDDDDDNMMNNNND8Z$7,~I:++++???7N88DOOODNZZZ$$$ZD$ZDOOZZ$ZOZOI7$$I7D$7D$$$I",
"$7777IZZ8$7777I?$8O$$Z$Z8DI$O7I$8OZ$ZZ$$DZZO=:7I8DDDDNNNDDNNDOZ=,7?==+++++?+?I888OOZDD$$ZZZ$$$77$77OZZZZNZ7777$877$$$$$$",
"?DZ$7III7I777IZ$Z8$$7OIO?7IZI7$$OZOOZ7ZZZZ$O7.I$DDDDDNMMD8DDNZ.:8+~?~,~~~:,,,,~OOOOZ8888O$ZZ$Z$$777I$ZZD$777778$$$$$$$D8",
"77I7III77I7?8?Z7O$$7I77II777?O777$ODOZZOZZZOM+8+7NNMNNMN8OODN:.8,.=,~~,,........IOOZZDD8888$7$$Z$$7$IN8Z7777777$$$$$$$OZ",
"I77I7III777II77?8OI7I777I?777$D$$$$$$ZOZZZZZO:88$$8MNNMNO$ZN.=,,,::....,:::.,..,,.ZZ$D8ZOO8$$$O8I777777O?77$7ZO7$$$$$OI7",
"7777777777?$7I$778II77I7I$II$77$8O$Z$ZZ$ZOZO8D~8DOZDDDNN$7.~:~::,,.,=~:.....,~++=~+?N8$$$O8$$$$$ZOOZOOO$$$$IZ$I$7$$$7O$$",
"77777I77IDII77I7$OI777777$7$77$$$O$ZZZZZ$8OOOO$?DN+?DDNN,=?,:~.,:~+,,:........,,?+~=?8$Z$$Z$Z$$$DZDDOZZ$77D$$$7$$$$$OZ$$",
"OZ888$$I777777777OI777777I$$$$$$$$N8$ZOZZONOOO8N88+$N:?:::::.,.=,,,,..,,.,..,..::::=:I$ZZ$7O$$$$8$8I$8O77O$Z$Z$7$$$$D$$$",
"$I$D8O777777I7I$77I7777777$77$Z$$Z$O88O8DZOOOONN8N=+++:::=:~+~=::,.,::,,,,,,,,,:.:~I++=8ZZ$$O$$$ZO$$7$N$$8$ZZ87$$$$88$$$",
"O8$7O7777777$7ZI$Z7777777OZOI7$$$O7Z8O8OOD8DD8N88+:?,,+=~,?+~:::~,:,:,,,,,,,,:::,::~:=?:ZZ$$ZD$$$ZOD$Z7$$$8OOO$$$$OOZ$$$",
"ZO$$$7I777777OI$$$Z77777I778ZO8$$$$O$DODND7N8N8DZ:::~~:,=~:,,::,::,,:::~::::,:,:,::=?~~+,ZZZZNZ$DOZO$Z$Z77$$$D7$$7DOO8Z$",
"IOIN77777777Z77$77$O7I77I$$ZOO7Z888$$ZOZ8DONZ8+7.,.::~Z~,,,::,,,,:,,,,:::::~:::=,,:~:~N~:$OO$$$$$$777ZONZ$Z$$78$OZOZOODZ",
"77O?77$7778$ZZ$$7ZZD77$7ZO$$777O7$$N88ZOZ$OO8I=:..,~:?,.,,,:::,:,,:::~:,::,:,:,:::~+~~+7~~ZZ$$$$$$$$77$$$7$$7$IOZZZ$ND87",
"7$87$$777$I77IZ78ZZZ777D7$777NO$7$OD$O$8ZODZ:::.:,:~:,,,,::,:,+:~=~:~~~::~::::,=::~+=~~OI:$Z$8$Z$ZZO$777$$$77$8I$ZOND8DD",
"7DIZ$77DO7$7777$78D8D7I8$$7Z$$$7$78ZZ$ZZZOO=:,,~::~+~,,,,:::,~:=~=~:~:~~~~::~::~~:~?=~=Z+I$8O$Z8D7$$$ZZ$$ZZOZ$$ZZDD78O87",
"$88$OOZ$$$$$$$77777$$I$$$$8777$$77$ZZ$OZO:+.,:~,:~?=,=:,::~::+=:~~::::,~~~:~~::~~:=?+~?Z7+?ZO$O888OZO$$7$$$$$8Z7$Z8ONNDO",
"7777777Z$$7$Z$$$7Z8N7$I7Z8$7$$$$$ZZZZOZZZ,::7,,~,=:,=:~,::~~=~=~:~::~~:::~:~:::~~~~++=?$I~,ZZDOZ7DZ$$$$$$8$7D7$$$8Z8Z8ZZ",
"$7777$7$777$$$$7O$7Z8DO$7$$$7$$$77$Z8$Z,,,::,.,.=~,,,=~~~+:=?~:=+===~=~:::~~~=:~=~=+$=IZ7~~$$OO8Z$$$$$$$$Z$$$D$Z$$ODZZM$",
"77$7OZ$7$$$$7$777$7O$8D7$$7$$777$$$Z8?=.:,,,,,.~:,.:~=+=~++?++====~==::::::::~=:=+=+?+$$7=7Z8O7$$$$$$$$$$$$$$Z$Z$ZZDZ$8D",
"ZZZ$77$7$$777777$$8ZD8O$7$7777ZOD$$Z.,..,::,,=:.,:.,:~=7=??7??+:~:~::::::~::~::?=+=++?$II77D$Z$Z$$$7$$$$$$$$$$$$8$NO$$ZO",
"777Z8$77$77777I8$7IZZ$77$$7ZZOOZZ$7.,8:=::.,,,.~=:::,,:=?+II?+:~~~~~~:::::::==:+~:?7?$$7+~+8$$Z$Z$Z$ZO$$$$$$$$$DZZZ$ZZN$",
"7$Z$OOZ8OOZ$$7$7$8$DZ77$$$7O77$O+,,~,,~~:::,::~+:,,~:::~~+?$?+=~~==:~~~==~~~:?:~=?++$O77?7.OODO$$$ZO$Z$Z$$$ZZ8$$ZZZZZZZZ",
"$Z7ZOZO77$$7$$77$$Z8ZZ$777$$Z$78,~=7~~:::,,,,=+::,,,,,~~~~=?O+==~===~~~~~::==+=+==~ZI$77+IO8888$Z8ZZO$$$$$$O7Z$ZZZ$ZNZ$O",
"$$$ZO$$$$$$$$$$$$Z$$I7ZZDDZO$7OZ.?I$++++=~:.:::,,,,,,:::~~==?~=~~=::~~=~~~:~~~~==+I$+7Z7I?ZZZ$8ZZZZD$$$$$ZO$$OZ$ZZZO$$ZO",
"$O8$$$$$78$$7$$$87$Z$7OZDOZOOOZ8DZOOI7:=?:~:,::,:::,,,,:::~=~====~~~~~==~~++?~7~~??7OI?=?N$$$88O8DN8$$$$$OZOZ$ZZZ$8$Z$OO",
"OO$7$Z7$$$77ZO$$8$O7IO7DZO$$$$ZO$OOO$7$I++$,,.~~:,,,=~::,,:~====~=~=~::~:+=+==++=+?$7?I+:ZZZZ$$$$8DZ$$$$888ZZ$DZZDZZZZZZ",
"$Z$$DZZO$DOOO7$$ZNOINDOZ7Z$ZO$$7ZOZ$II7?I=+$++?,~:=.,,:+~:~~==+~=~~~=~~~~=+++~+++?IO77??$ZZZZ$$$$ZOZ$$DZN8ZDDZZZZDZZOOOZ",
"$$$$$$$$$$OO$$O$8I77$O7$$Z$$$O8Z$Z$7++7++?+$?I+==:~====:=:=~++~+=~=~==~~+++===?++?I$77I+OOZZZZZZZZOZOZ8$88Z$$8OONOZZOZZ8",
"$$$$$$$$ZDOO7Z7O7$O$7O$O$$7$$$7$DZ7I+??++?+=I:==?==~:~:=~:==+~~==+=~~~~==?++==+==IO$Z+7OOOZZZNZ$$ZZDZZZ$Z8$$$NZDNOZZZ8N8",
"$7$$$$7O7Z$87O7D$777$7$$$$7O$$$$ZZ$I?+?+++===:?=:~~++:~:~,=+:=+++=~~~~~:++=+~=?+?IO$7?ZOZZZODDZZZZZOO888DZZ$Z$8ZONZDOD8Z",
"8Z8ODZOO$$7OO$Z$$$$$$$$$$$$77$$ZZOZ7+?+++++=~=,,~=+~~:~~~?=~+=+=~==~=~=++++?=?+=I7O?IOD8OZOZZOZ8ZZZZZZZZ$Z$88888ZZZODOD8",
"D8OOOOD$Z$$7ZO$Z$$$$7$$$$$$$Z7$ZZZ7$I?++++=~==~:,,~===~::~?+~+==++=~~~=+?=++~I?I?I$$DN8888DOD$8Z$ZZZ$$Z$ZO8$Z$D8DDDD8DD8",
"$88O8OO$$$$$O7$$$$$$DOZ$$$$$$O$ZZ$$$I?++++=~:~~=:,,,:~~:~~=+=====~~~~==+??+++I=IIOOMNDD88OD88ZZZZZZZZZZZZZZZZZZNDOODDODD",
"$$8ZOD$$$$$7$$$$$$$Z8D$$$$$ZZODZZ7$II?++++==~~::~~:,,,,,:====~+=+=~~=~+==I?==I+$7$NDDDD8D888OOO888ZOO$D8DD$ZZ$ZOM8MDD$N8",
"Z$ZZ$88$$$$$8$$$$$$8Z$8Z$ZZZZZO8OI$7??+++===~~~::~~~~:,,:=+?~++~==~~~=?=+=++II?O?MMNDDNDNDOO88DZDO$ZZZZZZZZZZZNZ8DNDZZZZ",
"8888Z7$$$7$Z7$$$$$$ZO$$Z$$$ZZZ$88?7$??++?========~,:~~:~~?=+===~~~~,=++=+?I?+7=Z$MMNMMNDD888ON88ZZZZZZZZZZ$8$O87DD8ZZZZZ",
"8N8O8$$$O8$8$$$$$$Z8ZZZ8$ZZ$$Z$DDI7$?????+++~:,:~=+~:,,::+?+===+=~~~+?+I????=7Z$MMMMMMMNND8DNZZOZZZZZZZZZZZZ$8ZN$8O$ZOOZ",
"D$OZ8$7OZ$Z7$Z$$$$8$$Z$ZO$$ZZZZND$II??+++=~~~~~:,,,,:~:~=+?+==~~~~==?=+=+I+?+IZ$MMNDND888M8ZOOZZZZZZZZZZZZ$DZZZZZZZZZOOO",
"ZZZZNOOD8$O87$$$$$7$Z$ZZ$88$ZZZ8N$$I??++++=~~~~~~:,:::~=====~==~~~~??+I?+I===IZ$NNNNNDD88OZO8ZZOOO$ZZ$8NN8ZZOZZZZZOZZZOO",
"D$Z$$$$$NO88$ZZ$N8OOZ$$$$DZN$OZ8O7$7???++==~==~~~~::~==::++~~====~=~+~~+++I?I?OMNNNNDD888OZO8DD8N8ODD88$ZOZZZZZZN8DZZOOZ",
"O8$Z$8$$$ZO8$ZZZDOODZ$$Z$8DN8OZN87$$??++++~=~~:::::~::,,:~7II7I+=+=+?I+?+=7??ZZMNNNDDD8O8NDOODOD8ZOZZ8DZZZZOZZZ8$ODOZOZZ",
"OZZD8OZZ$$$$8$8O8ZZODZZZDZZZOO88D777?I+++++===~~:::,,,,:~I77++++?++++?++I=??=IMMNDDDNNDD88O88ZDD$8DOZOZOZZOZZZDDOZNOOOZO",
"$$$$$$Z$O8$$8OOOOZDDOOZZ8ZZON88DD8$$?I++====~=~~~~::~~~:~+I=~=++++???+I??+??7ZOONND888DD8O8OD8DDDDONZOZZOZZZONZOOND8ZOZO",
"$$Z$$$$7$$$$$O8ZDD$D8OD$OO$DO8DDDD$$II++==~~~~~~===~:::~+?+?~~+?++?+===?I$?+Z8O+=~IZD888ODDNDN8OOOO8DZZZOZZ8DD8OOONN8OOZ",
"$ZZZZZZ8DZ$$$8ZO8ZONOD888DD888DDD87$77I++=~=~~~=~~:,:~====7??+=~,~=?=~++==I?$ZI++==+I888OOOZNN8OOOZZ8OOZZOOOZZZDDMDDNOZO",
"8D8ZZZ$Z$ZZO8ZO788O8$8D88DD8MDDNDN$Z7II??+++==~:::::~~~~~~I7+NO:,ID,O?+,$$=+O$I++==I$ND88ODN8DM88OOONOZOONOZZOZZOZN8NMZO",
"Z$ZZ$ZZ$7$8$$$$$ZO$O8O88NDDMNDDNNM$7++7?~==~==????+++====?+??MZ+O:Z.$:M=?~,7ZI+++==??$MDNDNZODDDOZ88D88N88OOO8ZZZO$DOODN",
"$$$$ZZZ$D$$$$Z$$ZZZZZON8ODNNNDDDNM8$7II?+=~::,,,,:,,,,,:~=OZ???+~~?~I=+II::+??+++=+II=D8DOO8ONONDOO8ZZZO88NOOO88OODDNOOZ",
"$$ZZZZ8$ZZZ$ZZZDZZOZO888DMN8NDDDN?$7??I7?+=~~:~~~~~:~~~==I$=~~~DIID??O$:==?8????+=?I7DND8888OD8OOOOOOZZZOOZZZOOZDNDN8NDD",
"ZZZZ$N$$ZZZZZZOODNZZZZDOMDDNDDDNNN?~III?++~~~:::::::::::~+=::.$I~87?=I++?,=N??+?++I77MNDD8N88ODOOOOOOZDOOOZOOZZ8OZO8ND8N",
"ZZ888ZZZZZ$ZZD$$ZZZOOOODO8DDMNDM?$?I?I~:=~::~===~~~::::::==:+=:~~=I~+I=??=I=+?+?=IZ$ZNNNDD888DDDD8NDZZZOOOOOOOZZOOOMNDDZ",
"OZOZ$ZZZZZZZ$$Z$ZOOZ8ZON88DDDMN+?++Z+=~++=~~~,,:,,,:,,:::=?DZZ:,=~:,~=.8N+:==++?=I7IMNNNDD8DNN8ZOOOOZNOOOOOOOOZ8NDZONMDO",
"OZZZ$ZZ$ZZOZZZZZZ$Z8ZZO888DDDM+~=+~::::?~~::,:::~:,::=~,,~?8O$$ZOOO8D88DN$I?8I++=I$$NNNMMN8888OOOZDOODDD8DD8ZOZOOONONNZN",
"ZO8$ZZZZ$Z$ZZZZZZ$OZ$OO88DDDD$=+=~=~~~,,:,,~~~:,,::.,,,::=Z$7777$ZO888DDI$ZI?O??=$OMNMMDND8888OOO8OODDD8OZOOOOOZDOODDDN8",
"$ZZ$$$Z$NZ$ZZ$$ODZZZ8O888DDD$+~++I==~~:~~~,~::,:~:~,.,,:~7$$7777$$Z888DNZ?I77?DMN88MMNNNNDDD8888OO8DD8OZOOOOOOOO8OO8DOOD",
"DD$ZZZZND88DZOZODZZZO8O8D8D7I=$I+=:,~=::~~=::~~~+:,,:,::=Z$$777$$$ZOOODOI$++?$INNDO$MMMMNNDD888D8DDDZZOOZZDOOOOZZDO8ZZZD",
"ZO$Z$DZO8NNDZ$Z$8$ZZO888DD+I++???=+~~=::=~+:~==:~:,,,:::$$$77777$$ZZOODOII7+$$8?DDZOMMMMMNNDDDD8NNDO8OOOOOOZODDOO8ONONDM",
"$Z$D8DZD8OZ$O8OOOZZOOONDD8++I=?+I=:=~~~=?:~=+=~~~,,,::~~$$$7777$$ZZZZ88ZI?7I+7$$?8Z$DMNNNNDDD88N8OOOONDDDDDDD8OOD8DDDODZ",
"$Z8$ZOOZOZZZ88DDZZ8O8DNDDO=+?7~=+~:=~~~~++====~:=::,::~+Z$$$7$7$$$ZZO877$??$==7Z?7Z+77NMMNNDDD8OOOOOOOOOOOODNO8D8D88ZD8M",
"ZZZZZ7ZO8DZ$O8NOOZ8ODDDMM7=?~II+?::==~=~~=+~==~:=~::,:=ZZ$$77$$$$ZZO8DII$+?7I==77+O==IMNNNNNDD88888OOOOOO8NDDOONNOOOOMOO",
"ODD88ZZ$ZZ7DDD8N8888N8MN8++I++?7:=++~~:==+==+~::~~::,:=ZZ$$7777$$ZZOD$??I=+??==+7?++~IIMMNNNNDD888OOOOODND8ONOO8OON88MOO",
"ZZZZZZZZZO8D$O8D8DDN8NNM+7+?Z+I+?=+?=~~+I=====:::=~::~7ZZ$$77$$$$ZOO8+++??++I?==I7?Z~?$MNNNMMNDNNDNDNDD8DOONDONOOD8OONOO",
"ZZZZZZZZZ$D8NDO8DDD8N8DN=I++??Z=~=~+~~+++==~=~::~=~::=ZZ$$$$$$$$ZZO8$++=+I=+I+==?7??==I7NNNNNNDDDDDDDD8ZOOOOOOZOOOOOONOO",
"ZO$DNO8O$ZZZZZZ88O8N8DD8+?+?=?:~+:~+=+?=+=~:~~::~=~::+Z$$$$$$$$$ZZO8?+===?~=???==7I78+IINNNNMDNNDDNNDDDOOO88O8ZOOOOONNO8",
"8$ZZZZZZZZZZZN7ODDDO88D+??+??$?~~~======?=~:~~::~~~:~ZZ$$$$$7$$ZZO8O?+==~====?==+=IZ$+?7IMMDNMNNNDD8NNZOOOOZDDO8OO8OD8NO",
"ZZZZZZZZZONOZNON8DOO88D??=+7I7+=~~====+===~~:=:~~:~:~ZZ$$7$7$$$ZZO8++=~~~~?~=+=+=+IIIOII+NNNNMNNNNDDD88OOOONDOOOOOONZ8Z8",
"ZZZZZZZZZZZZ8Z8ZDND888NI=~=II+:==~++==~=~~:~:=:~:~~~=ZZ$$$$$$$$ZO8O?+=~~~~+~~=?=~=+$$D~Z?=NNNNNMMMMNNN88OON8D8O8OO8NOO88",
"ZZZZZZZZ$8OOZZOZNO88D87+++?7$?+==~=~==~~~~:~:=:~:~~~?ZZ$$$$$$$ZZO8++=~~~~~==~=+====7Z+D$??NNNNNMMMMMMDD8NN8Z8O8O88888O88",
"DD8O$D88ZZZZOZZ$8O8888+?==?77$+~===~~+==~::~:=~~:~~~ZZ$$$$$$$ZZO88+?=~~~~~~?~~=?~===$?~~??=NNNNMMNNNMDDNDDOND88O8ON88O88",
"ZZ88O8OZZZZOOZZNOOD8DD?+==$77:+=+=~~===+~::~,=:~:~~=ZZ$$$$$$$ZZO8I++=~~~~~~==~~?=~=+I=??7?+7NMNMMMNNDNDND8DD88O88DND888O",
"D8DZZNZZZZOOZZZ88D88DNI+==$7?I+~~~===~~~~::~:=:~:~=7Z$$$$$$$ZZZOZI+=~=~:~~~~+=~~~~==+$=+~+?+MNNMMNMNDDD888ND8OOOD88MO8OO",
"88DZZO$ZZOZZZZDZODN8D$++++OO+~?~==+==+:~~::::~:~:~+ZZ$$$$$$$ZZOO+?====~~~:~~~==~=~==+?II??+??+8MMMMMNDDD888DNODD8888D888",
"ZZ8NDZZZZZZZDOZO8DDMD7++II8?=+=+++=~==+~~~:::~:~~=IZZ$$Z$$$$ZZOII=+==~~~~~~~~=+=+~===?7+?:+7?77=DDDNDNDND88OODNDDD8DNO8O",
"ZZZ8ZZZZZZZ8ZODO8DDND7?+II87==~=~=~~==~:~::::::~~+ZZ$$$$$$$ZZOO?I===~=~~~::~~==+?~~=++I?Z$?Z7$=+8NNNNDDD88DDDD888NDMNDO8",
"OZZO$ZZZ$ZZZZOZZD8DNN?I+?$$,~====~~=~++:~:::::~~=+Z$$$$$$$$ZZOI?7===~=:::::~~~==?~~===7IZ$7Z777+:~NNNNNMDNNDNDDNNNNDDDDN",
"ZOZOD$ODOO8OOZOOO8DDD?+?I77=+=~~=~:~~+==~:::,~~=+$$$$$$$$$$ZOZ++?==~~=:::~:~~~==?~~~=+?OO,7$$++?=~,NNDDD88O8DONNDDNNN8ND",
"8Z$OD888ONOOOOOO8DDD++7Z77~===~==~:::?:=~:~::~=++Z$$$7$7$$ZZO++=?==~~~:::~~~~~~~++~~==+OZ+$OI+??=~INDDD8N8OD88O88D8NDODD",
"ZZZZZZZZZZO8DDDDD8DD$$~I$++~=~===~:~~$~=~::::~??Z$$$$$$$$$ZO?+==+~~~:~:::::~:~~~=I~====IO:,O7I7+?+:DDDD8888ODOO88D88N8NN",
"ZZZZZZZZZZZZZOOOO8DM???7$I++===~~:~~:~=~~::::~II$$$$$$$$$$ZO==~=+~~~~~::~::::~~~=+=~=~+=OZ$:I?Z++~=~DDDD8888OOOD8DD8O8ND",
"8ZZOOZZZZZZZZZZ8DDNNI?I$O?+=~~+==~::~:~~~::::=7Z$$77777$$ZO?====+~~~~~:::::::~~~=++~==++?~O=,7I7I??+MNDD888888DDODDOOOND",
"OOZZ88ZZZZOOZZZO8DNDI+?$I=?+=~=~~~~:~::=~:::~=ZZ$$$77777$ZZ==~~~+~~~:~:::::::::~==I~~==?++?~=77$II?+ZDDDDD888OD8OO8DO8OD",
"ZZZZ$ONDNNDNN88O8DDI7I+ZI?=I~+====::~~7~~:::~+$$$$$$77$$$O?=~~~~+~~~:::::::::~:~~=I=~=+++==I:7IO+Z=:.DDDDDD+=IIO8O?8OZDD",
"8ZOZD8DDDZZZOOO8DNN$7I7?++~~~~=~=~~~:=~~~::~=ZZ$7$7777$$Z+7=~~~~=~~~:::::::::::~~=+=~=+++~?=~7I$I=I=ODDDDD?D=.~88DN7D+NO",
"ZZZD8D$ZZZZZOZ88DDN??7I+I+==?+==~::,~=~~~:~++ZZ$7$$7$7$$O=I=::~~=~~~::::::::::~~~=++:~++=~~+=I7$7=7?~DDDDD88OOOOOODO88DO"
};

static char *aoiyu_join(const char *delimiter)
{
    int ii;
    for (ii = 0; ii < NUM_ROW; ++ii) {
        php_printf("%s%s", aoiyu_image[ii], delimiter);
    }
}

PHP_FUNCTION(aoiyu_awesome)
{
    zval **str;
    char *s;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "Z", &str) == FAILURE) {
        RETURN_FALSE;
    }
	if (Z_TYPE_PP(str) != IS_ARRAY) {
		if (Z_ISREF_PP(str)) {
			SEPARATE_ZVAL(str);
		}
		convert_to_string_ex(str);
	}
    s = Z_STRVAL_PP(str);
    aoiyu_join(s);
    RETURN_TRUE;
}
