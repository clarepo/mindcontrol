/*
 * CalibLib.h
 *
 *  Created on: Oct 15, 2009
 *      Author: andy
 *
 *      The Calibration Library is the library that deals with transforming between
 *      the camera, OpenCV and DLP. Perhaps Transformation Library would be a better name.
 *
 *      The idea is Calibration Library can include both the Talk2Camera and Talk2DLP libraries.
 *
 *      It is also the place to store frame structures. For example a FromCam structure could have
 *      camera specific frame storage as well as an OpenCV version.
 */




/*
 * This structure contains information about calibrating the DLP to the CCD
 *
 */
typedef struct CalibDataStruct{
	int* CCD2DLPLookUp;
	CvSize SizeOfDLP;
	CvSize SizeOfCCD;

} CalibData;



/*
 * Create and allocate memory for the CalibData structure
 *
 * Currently SizeOfCCD is stored but not really used
 *
 */
void CreateCalibData( CalibData* Calib,CvSize SizeOfDLP, CvSize SizeOfCCD);

/*
 * Deallocate memory for CalibData object
 */
void DestroyCalibData(CalibData* Calib);




/*
 * Read In Calibration Frome File
 *
 * Returns 1 if open failed.
 * Returns -1 if open succesfully but read fails.
 */

int LoadCalibFromFile(CalibData* Calib, char * filename);
