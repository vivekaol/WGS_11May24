WGS
The WGS software was design by FXLynx Technologies to give the most compact solution to use Octasic’s software defined radio platform features.

Architecture

The WGS architecture is defined in detailed on the Software design doc

In our case the only TCP client the WGS server has is the MCH application.
The MCH is communicating with the WGS using the WGS API.
To understand the flow of each of the 4 major capabilities please look at the following docs:

Scanner desgin doc
GSM catcher desgin doc
UMTS catcher desgin doc
LTE catcher desgin doc




Prerequisites
To start developing please follow FxLynx Build Environment setup guide

Upgrading a new Layer 1 version
Once every few months Octasic release a new version of its Layer 1.
The changes can include bug fixes, API changes and new features.

Compiling Layer 1
The step for upgrading a new L1 version is as follow:

Connect to Octasic support forum release tab
Select the requested RAT/RUS link
Go over each of the available release notes to select the correct image you like to upgrade.
** Note: ** L1 ADF version must be compatible for RUS, 2G and 4G.
So, when a new version is release you must make sure that you upgrade all images and not just a single RAT image.
Click to download the zip file. ** Note: ** you must agree to the license agreement before the zip file is downloaded.
Unzip the file to the centOS VM under
Change clock to 10MHZ in hardware/utils/bootscript/target/config/octbts3500.ini =>  ClockReferenceSource=10MHZ

Copy the license file to <unzip folder>\hardware\utils\bootscript\target\license

go to hardware/utils/bootscript/target/octsdr_<rus/gsm/umts/lte>/

Run the following command bootimggen.bat.bat --boot_file=octsdr_<rus/gsm/umts/lte>.boot --board_prop=..\..\hardware\octbts3500.properties --lic_file=..\license\OCTLIC-B3500-979200-001.lic



Testing Layer 1
It’s better to compile the OCTSIC example in order to check that the new image is running correctly.

Inside the centOs VM, Go to application\sample\rus\wnm

Open terminal
Run make -f wnm.mak

Goto Debug folder
Upload the wnmd file to the board into home/wnmd

Upload to the board /tftpboot/octsdr_<rus/gsm/umts/lte>.imag

Upload the image using the command obm dr octsdr_rus.img

Run ./wnmd -s <obm bi mac address> -d <obm di mac address> -m:0 -t:<RAT> -b:<bandNum>



Deployment

Layer 1

WGS