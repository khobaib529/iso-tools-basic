#ifndef ISO_TOOLS_PRIMARY_VOLUME_DESCRIPTOR_H_
#define ISO_TOOLS_PRIMARY_VOLUME_DESCRIPTOR_H_

#include <cstdint>
#include <cstdio>
#include "iso-tools-basic/directory-entry.h"
using namespace std;
namespace iso_tools {
constexpr int kSectorSize = 2048;
constexpr int kPVDSector = 16;
constexpr int kPVDOffset = kPVDSector * kSectorSize;

class PrimaryVolumeDescriptor {
 public:
  void PrintRaw() {
    const uint8_t* raw = reinterpret_cast<const uint8_t*>(this);
    for (uint32_t i = 0; i < sizeof(*this); i++) {
      printf("%02X ", raw[i]);
      if ((i + 1) % 16 == 0) printf("\n");
    }
  }

  uint8_t type;
  uint8_t identifier[5];
  uint8_t version;
  uint8_t reserved1[1];
  uint8_t system_identifier[32];
  uint8_t volume_identifier[32];
  uint8_t reserved2[8];
  uint32_t volume_space_size_le;
  uint32_t volume_space_size_be;
  uint8_t escape_sequence[32];
  uint16_t volume_set_size_le;
  uint16_t volume_set_size_be;
  uint16_t volume_sequence_number_le;
  uint16_t volume_sequence_number_be;
  uint16_t logical_block_size_le;
  uint16_t logical_block_size_be;
  uint32_t path_table_size_le;
  uint32_t path_table_size_be;
  uint32_t path_table_location_le;
  uint32_t optional_path_table_location_le;
  uint32_t path_table_location_be;
  uint32_t optional_path_table_location_be;
  DirectoryEntry directory_entry;
  uint8_t volume_Set_identifier[128];
  uint8_t publisher_identifier[128];
  uint8_t data_preparer_identifier[128];
  uint8_t application_identifier[128];
  uint8_t copyright_file_idenifier[37];
  uint8_t abstract_file_identifier[37];
  uint8_t bibliographic_file_identifier[37];
  uint8_t volume_creation_date_time[17];
  uint8_t volume_modification_date_time[17];
  uint8_t volume_expiration_date_time[17];
  uint8_t volume_effective_date_time[17];
  uint8_t file_structure_version;
  uint8_t reserved3[1];
  uint8_t application_use[512];
  uint8_t reserved4[653];
} __attribute__((packed));
}  // namespace iso_tools

#endif  // ISO_TOOLS_PRIMARY_VOLUME_DESCRIPTOR_H_
