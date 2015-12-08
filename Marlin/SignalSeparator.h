#ifndef SignalSeparator_h
#define SignalSeparator_h 1

#include "marlin/Processor.h"
#include "lcio.h"
#include <string>
#include <map>
#include <EVENT/ReconstructedParticle.h>
#include <EVENT/MCParticle.h>
#include <UTIL/LCRelationNavigator.h>
#include "TH1F.h"

using namespace lcio ;
using namespace marlin ;


/**  Example processor for marlin.
 * 
 *  If compiled with MARLIN_USE_AIDA 
 *  it creates a histogram (cloud) of the MCParticle energies.
 * 
 *  <h4>Input - Prerequisites</h4>
 *  Needs the collection of MCParticles.
 *
 *  <h4>Output</h4> 
 *  A histogram.
 * 
 * @param CollectionName Name of the MCParticle collection
 * 
 * @author F. Gaede, DESY
 * @version $Id: SignalSeparator.h,v 1.4 2005-10-11 12:57:39 gaede Exp $ 
 */

class SignalSeparator : public Processor {
  
 public:
  
  virtual Processor*  newProcessor() { return new SignalSeparator ; }
  
  
  SignalSeparator() ;
  
  /** Called at the begin of the job before anything is read.
   * Use to initialize the processor, e.g. book histograms.
   */
  virtual void init() ;
  
  /** Called for every run.
   */
  virtual void processRunHeader( LCRunHeader* run ) ;
  
  /** Called for every event - the working horse.
   */
  virtual void processEvent( LCEvent * evt ) ; 
  
  
  virtual void check( LCEvent * evt ) ; 
  
  
  /** Called after data processing for clean up.
   */
  virtual void end() ;
  
  int _choice;  

 protected:

  /** Input collection name.
   */
  std::string _colName ;

  int _nRun ;
  int _nEvt ;
  int nskipped;
  int npassed;
  int NumberHiggs;

  TH1F* _nleptons;
  TH1F* _nWDecays;
  TH1F* _ndecayproducts;
  TH1F* _ndecayPDG;
  TH1F* _nleptonPDG;
  TH1F* _ndecaytype;
  TH1F* _nParticleLeptonic;
  TH1F* _nParticleSemiLeptonic;
  TH1F* _nParticleHadronic;
  TH1F* _nParticleUnclassified;
} ;

#endif



