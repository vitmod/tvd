# - Find FusionSound
# Find native ginga includes and library
# This module defines
#  FUSIONSOUND_INCLUDE_DIRS, where to find the fusionsound header files.
#  FUSIONSOUND_LIBRARIES, the libraries needed to use fusionsound.
#  FUSIONSOUND_FOUND, If false, do not try to use fusionsound.
# also defined, but not for general use are
#  FUSIONSOUND_LIBRARY, where to find fusionsound library.

FIND_PATH(FUSIONSOUND_INCLUDE_DIRS fusionsound_version.h PATH_SUFFIXES fusionsound)
FIND_FILE(FUSIONSOUND_INCLUDE_VERSION fusionsound_version.h PATH_SUFFIXES fusionsound)

LIST(APPEND FUSIONSOUND_NAMES fusionsound )
FIND_LIBRARY(FUSIONSOUND_LIBRARY NAMES ${FUSIONSOUND_NAMES} )

# handle the QUIETLY and REQUIRED arguments and set FUSIONSOUND_FOUND to TRUE if 
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(FUSIONSOUND DEFAULT_MSG FUSIONSOUND_LIBRARY FUSIONSOUND_INCLUDE_DIRS )

IF(FUSIONSOUND_FOUND)
	SET(FUSIONSOUND_LIBRARIES ${FUSIONSOUND_LIBRARY})

	FILE(STRINGS ${FUSIONSOUND_INCLUDE_VERSION} FUSIONSOUND_VERSION_MAJOR REGEX ".*FUSIONSOUND_MAJOR_VERSION.*$" )
	FILE(STRINGS ${FUSIONSOUND_INCLUDE_VERSION} FUSIONSOUND_VERSION_MINOR REGEX ".*FUSIONSOUND_MINOR_VERSION.*$" )
	FILE(STRINGS ${FUSIONSOUND_INCLUDE_VERSION} FUSIONSOUND_VERSION_PATCH REGEX ".*FUSIONSOUND_MICRO_VERSION.*$" )
	STRING(REGEX REPLACE ".*FUSIONSOUND_MAJOR_VERSION.*([0-9]+).*" "\\1" FUSIONSOUND_VERSION_MAJOR "${FUSIONSOUND_VERSION_MAJOR}" )
	STRING(REGEX REPLACE ".*FUSIONSOUND_MINOR_VERSION.*([0-9]+).*" "\\1" FUSIONSOUND_VERSION_MINOR "${FUSIONSOUND_VERSION_MINOR}" )
	STRING(REGEX REPLACE ".*FUSIONSOUND_MICRO_VERSION.*([0-9]+).*" "\\1" FUSIONSOUND_VERSION_PATCH "${FUSIONSOUND_VERSION_PATCH}" )
	SET(FUSIONSOUND_VERSION "${FUSIONSOUND_VERSION_MAJOR}.${FUSIONSOUND_VERSION_MINOR}.${FUSIONSOUND_VERSION_PATCH}" CACHE STRING "Version of FUSIONSOUND as computed from fusionsound_version.h.")
	MARK_AS_ADVANCED(FUSIONSOUND_VERSION)

	# Always set this convenience variable
	SET(FUSIONSOUND_VERSION_STRING "${FUSIONSOUND_VERSION}")

	# Here we need to determine if the version we found is acceptable.  We will
	# assume that is unless FUSIONSOUND_FIND_VERSION_EXACT or FUSIONSOUND_FIND_VERSION is
	# specified.  The presence of either of these options checks the version
	# string and signals if the version is acceptable or not.
	SET(_fusionsound_version_acceptable TRUE)
	#
	IF(FUSIONSOUND_FIND_VERSION_EXACT AND NOT FUSIONSOUND_VERSION VERSION_EQUAL FUSIONSOUND_FIND_VERSION)
		SET(_fusionsound_version_acceptable FALSE)
	ENDIF()
	#
	IF(FUSIONSOUND_FIND_VERSION       AND     FUSIONSOUND_VERSION VERSION_LESS  FUSIONSOUND_FIND_VERSION)
		SET(_fusionsound_version_acceptable FALSE)
	ENDIF()
	#
	IF(NOT _fusionsound_version_acceptable)
		SET(_fusionsound_error_message "Requested FusionSound version ${FUSIONSOUND_FIND_VERSION}, but found unacceptable version ${FUSIONSOUND_VERSION}")
		IF(FUSIONSOUND_FIND_REQUIRED)
			message("${_fusionsound_error_message}")
		ELSEIF(NOT FUSIONSOUND_FIND_QUIETLY)
			message("${_fusionsound_error_message}")
		ENDIF()
	ENDIF()
	

ENDIF(FUSIONSOUND_FOUND)

MARK_AS_ADVANCED(FUSIONSOUND_LIBRARY FUSIONSOUND_INCLUDE_DIRS )