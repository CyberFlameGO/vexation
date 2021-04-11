LPSTR   TYPEDEF DWORD
HANDLE  TYPEDEF DWORD

IMAGE_DOS_HEADER      STRUCT
  e_magic      WORD ?
  e_cblp       WORD ?
  e_cp         WORD ?
  e_crlc       WORD ?
  e_cparhdr    WORD ?
  e_minalloc   WORD ?
  e_maxalloc   WORD ?
  e_ss         WORD ?
  e_sp         WORD ?
  e_csum       WORD ?
  e_ip         WORD ?
  e_cs         WORD ?
  e_lfarlc     WORD ?
  e_ovno       WORD ?
  e_res        WORD 4 DUP(?)
  e_oemid      WORD ?
  e_oeminfo    WORD ?
  e_res2       WORD 10 DUP(?)
  e_lfanew     DWORD ?
IMAGE_DOS_HEADER      ENDS

IMAGE_DATA_DIRECTORY  STRUCT
  VirtualAddress   DWORD ?
  isize            DWORD ?
IMAGE_DATA_DIRECTORY  ENDS

IMAGE_OPTIONAL_HEADER STRUCT
  Magic                   WORD ?
  MajorLinkerVersion      BYTE ?
  MinorLinkerVersion      BYTE ?
  SizeOfCode              DWORD ?
  SizeOfInitializedData   DWORD ?
  SizeOfUninitializedData DWORD ?
  AddressOfEntryPoint     DWORD ?
  BaseOfCode              DWORD ?
  BaseOfData              DWORD ?
  ImageBase               DWORD ?
  SectionAlignment        DWORD ?
  FileAlignment           DWORD ?
  MajorOperatingSystemVersion WORD ?
  MinorOperatingSystemVersion WORD ?
  MajorImageVersion       WORD ?
  MinorImageVersion       WORD ?
  MajorSubsystemVersion   WORD ?
  MinorSubsystemVersion   WORD ?
  Win32VersionValue       DWORD ?
  SizeOfImage             DWORD ?
  SizeOfHeaders           DWORD ?
  CheckSum                DWORD ?
  Subsystem               WORD ?
  DllCharacteristics      WORD ?
  SizeOfStackReserve      DWORD ?
  SizeOfStackCommit       DWORD ?
  SizeOfHeapReserve       DWORD ?
  SizeOfHeapCommit        DWORD ?
  LoaderFlags             DWORD ?
  NumberOfRvaAndSizes     DWORD ?
  DataDirectory           IMAGE_DATA_DIRECTORY 16 dup(<?>)
IMAGE_OPTIONAL_HEADER ENDS

IMAGE_FILE_HEADER     STRUCT
  Machine              WORD ?
  NumberOfSections     WORD ?
  TimeDateStamp        DWORD ?
  PointerToSymbolTable DWORD ?
  NumberOfSymbols      DWORD ?
  SizeOfOptionalHeader WORD ?
  Characteristics      WORD ?
IMAGE_FILE_HEADER     ENDS

IMAGE_NT_HEADERS      STRUCT
  Signature    DWORD ?
  FileHeader   IMAGE_FILE_HEADER <?>
  OptionalHeader IMAGE_OPTIONAL_HEADER <?>
IMAGE_NT_HEADERS      ENDS

IMAGE_SECTION_HEADER  STRUCT
  Name1             DB 8 DUP(?)
  UNION
    PhysicalAddress DD ?
    VirtualSize     DD ?
  ENDS
  SecHdrVirtualAddress    DD ?
  SizeOfRawData     DD ?
  PointerToRawData  DD ?
  PointerToRelocations DD ?
  PointerToLineNumbers DD ?
  NumberOfRelocations  DW ?
  NumberOfLineNumbers  DW ?
  SecHdrCharacteristics DD ?   
IMAGE_SECTION_HEADER  ENDS

IMAGE_EXPORT_DIRECTORY STRUCT
  ImageExportCharacteristics           DWORD      ?
  TimeDateStamp             DWORD      ?
  MajorVersion              WORD       ?
  MinorVersion              WORD       ?
  nName                     DWORD      ?
  nBase                     DWORD      ?
  NumberOfFunctions         DWORD      ?
  NumberOfNames             DWORD      ?
  AddressOfFunctions        DWORD      ?
  AddressOfNames            DWORD      ?
  AddressOfNameOrdinals     DWORD      ?
IMAGE_EXPORT_DIRECTORY ENDS

WIN32_MAX_PATHLEN     EQU 260

FILETIME STRUCT
  dwLowDateTime     DWORD      ?
  dwHighDateTime    DWORD      ?
FILETIME ENDS

WIN32_FIND_DATA STRUCT
  dwFileAttributes      DWORD      ?
  ftCreationTime        FILETIME <>
  ftLastAccessTime      FILETIME <>
  ftLastWriteTime       FILETIME <>
  nFileSizeHigh         DWORD      ?
  nFileSizeLow          DWORD      ?
  dwReserved0           DWORD      ?
  dwReserved1           DWORD      ?
  cFileName             BYTE WIN32_MAX_PATHLEN dup(?)
  cAlternate            BYTE 14 dup(?)
WIN32_FIND_DATA ENDS

INVALID_HANDLE_VALUE  EQU -1
FILE_ATTRIBUTE_NORMAL EQU 80h
OPEN_EXISTING         EQU 3h
CREATE_NEW            EQU 1h
GENERIC_READ          EQU 80000000h
GENERIC_WRITE         EQU 40000000h
PAGE_READWRITE        EQU 4h
FILE_MAP_WRITE        EQU 2h
IMAGE_DOS_SIGNATURE   EQU 5A4Dh ; 'MZ' (little endian)
IMAGE_NT_SIGNATURE    EQU 4550h ; 'PE' (little endian)
IMAGE_SUBSYSTEM_WINDOWS_GUI EQU 2h
IMAGE_SUBSYSTEM_WINDOWS_CUI EQU 3h
IMAGE_FILE_MACHINE_I386 EQU 14Ch
IMAGE_SCN_MEM_READ    EQU 40000000h
IMAGE_SCN_MEM_WRITE   EQU 80000000h
IMAGE_SCN_MEM_EXECUTE EQU 20000000h
IMAGE_SCN_CNT_CODE    EQU 00000020h
HKEY_LOCAL_MACHINE    EQU 80000002h
ERROR_SUCCESS         EQU 0h

READ_CONTROL                         equ 20000h
STANDARD_RIGHTS_READ                 equ READ_CONTROL
STANDARD_RIGHTS_WRITE                equ READ_CONTROL
STANDARD_RIGHTS_EXECUTE              equ READ_CONTROL
STANDARD_RIGHTS_REQUIRED             equ 0F0000h
STANDARD_RIGHTS_ALL                  equ 1F0000h
REG_OPTION_RESERVED                  equ 0
REG_OPTION_NON_VOLATILE              equ 0
REG_OPTION_VOLATILE                  equ 1
REG_OPTION_CREATE_LINK               equ 2
REG_OPTION_BACKUP_RESTORE            equ 4
REG_NONE                             equ 0
REG_SZ                               equ 1
REG_EXPAND_SZ                        equ 2
REG_BINARY                           equ 3
REG_DWORD                            equ 4
REG_DWORD_LITTLE_ENDIAN              equ 4
REG_DWORD_BIG_ENDIAN                 equ 5
REG_LINK                             equ 6
REG_MULTI_SZ                         equ 7
REG_RESOURCE_LIST                    equ 8
REG_FULL_RESOURCE_DESCRIPTOR         equ 9
REG_RESOURCE_REQUIREMENTS_LIST       equ 10
REG_CREATED_NEW_KEY                  equ 1h
REG_OPENED_EXISTING_KEY              equ 2h
REG_WHOLE_HIVE_VOLATILE              equ 1h
REG_REFRESH_HIVE                     equ 2h
REG_NOTIFY_CHANGE_NAME               equ 1h
REG_NOTIFY_CHANGE_ATTRIBUTES         equ 2h
REG_NOTIFY_CHANGE_LAST_SET           equ 4h
REG_NOTIFY_CHANGE_SECURITY           equ 8h
REG_LEGAL_CHANGE_FILTER              equ REG_NOTIFY_CHANGE_NAME + REG_NOTIFY_CHANGE_ATTRIBUTES + REG_NOTIFY_CHANGE_LAST_SET + REG_NOTIFY_CHANGE_SECURITY
REG_LEGAL_OPTION                     equ REG_OPTION_RESERVED + REG_OPTION_NON_VOLATILE + REG_OPTION_VOLATILE + REG_OPTION_CREATE_LINK + REG_OPTION_BACKUP_RESTORE
KEY_QUERY_VALUE                      equ 1h
KEY_SET_VALUE                        equ 2h
KEY_CREATE_SUB_KEY                   equ 4h
KEY_ENUMERATE_SUB_KEYS               equ 8h
KEY_NOTIFY                           equ 10h
KEY_CREATE_LINK                      equ 20h
KEY_READ                             equ (STANDARD_RIGHTS_READ + KEY_QUERY_VALUE + KEY_ENUMERATE_SUB_KEYS + KEY_NOTIFY) &~ SYNCHRONIZE
KEY_WRITE                            equ (STANDARD_RIGHTS_WRITE + KEY_SET_VALUE + KEY_CREATE_SUB_KEY) &~ SYNCHRONIZE
KEY_EXECUTE                          equ KEY_READ
KEY_ALL_ACCESS                       equ (STANDARD_RIGHTS_ALL + KEY_QUERY_VALUE + KEY_SET_VALUE + KEY_CREATE_SUB_KEY + KEY_ENUMERATE_SUB_KEYS + KEY_NOTIFY + KEY_CREATE_LINK) &~ SYNCHRONIZE
REG_SZ                               equ 1h

 
