## pSniffer

Capture and process network packets on a specified network device using the libpcap library. 

It takes the name of the network device as a command line argument, opens the device using pcap_open_live, sets filters for the desired packets using pcap_setfilter, captures and processes the packets using pcap_loop, and finally closes the device and frees up resources using pcap_close. 

If any errors occur, the code prints error messages to stderr.
