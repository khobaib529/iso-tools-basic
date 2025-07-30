#ifndef ISO_TOOLS_DIRECTORY_ENTRY_H_
#define ISO_TOOLS_DIRECTORY_ENTRY_H_

#include <cstdint>
namespace iso_tools {
class DirectoryEntry {
 public:
  uint8_t length;
  uint8_t extended_attribute_record_length;
  uint32_t location_of_extent_le;
  uint32_t location_of_extent_be;
  uint32_t data_length_le;
  uint32_t data_length_be;
  uint8_t recording_date_time[7];
  uint8_t file_flags;
  uint8_t file_unit_size;
  uint8_t interleave_gap_size;
  uint16_t volume_sequence_number_le;
  uint16_t volume_sequence_number_be;
  uint8_t length_of_file_identifier;
  uint8_t name;
} __attribute__((packed));
}  // namespace iso_tools

#endif  // ISO_TOOLS_DIRECTORY_ENTRY_H_