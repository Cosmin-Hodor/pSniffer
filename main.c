#include <stdio.h>
#include <pcap.h>

int main(int argc, char *argv[]) {
  char *dev;               /* Numele dispozitivului de retea */
  char errbuf[PCAP_ERRBUF_SIZE];  /* Buffer pentru erori */
  pcap_t *handle;          /* Handle pentru dispozitivul de retea */

  /* Verificam argumentele de intrare */
  if (argc != 2) {
    fprintf(stderr, "Usage: %s device\n", argv[0]);
    return -1;
  }

  /* Salvam numele dispozitivului de retea din argumentele de intrare */
  dev = argv[1];

  /* Deschidem dispozitivul de retea pentru capturarea pachetelor */
  handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
    return -1;
  }

  /* Setam filtrele de capturare pentru pachetele dorite */
  if (pcap_setfilter(handle, &fp) == -1) {
    fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
    return -1;
  }

  /* Incepem capturarea pachetelor si procesarea lor */
  pcap_loop(handle, 0, process_packet, NULL);

  /* Inchidem dispozitivul de retea si eliberam resursele alocate */
  pcap_close(handle);
  return 0;
}