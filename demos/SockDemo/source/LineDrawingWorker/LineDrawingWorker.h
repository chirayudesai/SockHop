// This file, and all other source files that make up
// SockDemo, are placed into the public domain.  - Jeremy Friesner
 
#ifndef _LINEDRAWINGWORKER_H_
#define _LINEDRAWINGWORKER_H_

// This file implements a SockHop add on thread (SHWorker subclass)
// that opens a window at a random position on the screen, and
// draws lots of random lines into the window.  It also sends
// a BMessages every second to the root node, saying how many
// lines it has drawn in the past second.

#include <sockhop/SockHop.h>
#include "LineDrawingWindow.h"

#ifdef __INTEL__
_EXPORT class LineDrawingWorker;
#else
#pragma export on
#endif

class LineDrawingWorker : public SHWorker
{
public:
   LineDrawingWorker(const char * name);
   LineDrawingWorker(BMessage * archive);
   ~LineDrawingWorker();
   
   static BArchivable * Instantiate(BMessage * archive);
   
   virtual status_t GetAddOnSpec(SHFileSpec & spec) const;
   
   virtual const char * GetName() const;
   
   virtual status_t Archive(BMessage * archive, bool deep=true) const;
   
   virtual void MessageReceived(BMessage * msg);
   
   virtual bool IsInterestedIn(BMessage * msg);

private:   
   char * _name;
   LineDrawingWindow * _window;
};

#ifndef __INTEL__
#pragma export off
#endif

#endif
