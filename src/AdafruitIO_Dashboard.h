//
// Adafruit invests time and resources providing this open source code.
// Please support Adafruit and open source hardware by purchasing
// products from Adafruit!
//
// Copyright (c) 2015-2016 Adafruit Industries
// Authors: Tony DiCola, Todd Treece
// Licensed under the MIT license.
//
// All text above must be included in any redistribution.
//
#ifndef ADAFRUITIO_DASHBOARD_H
#define ADAFRUITIO_DASHBOARD_H

#include "AdafruitIO_Definitions.h"
#include "Arduino.h"
#include "blocks/ChartBlock.h"
#include "blocks/ColorBlock.h"
#include "blocks/GaugeBlock.h"
#include "blocks/ImageBlock.h"
#include "blocks/MapBlock.h"
#include "blocks/MomentaryBlock.h"
#include "blocks/SliderBlock.h"
#include "blocks/StreamBlock.h"
#include "blocks/TextBlock.h"
#include "blocks/ToggleBlock.h"

// forward declaration
class AdafruitIO;
class AdafruitIO_Feed;

/**************************************************************************/
/*! 
    @brief  Class for interacting with Adafruit IO Dashboards.
            https://io.adafruit.com/api/docs/#dashboards
*/
/**************************************************************************/
class AdafruitIO_Dashboard {

public:
  AdafruitIO_Dashboard(AdafruitIO *io, const char *name);
  ~AdafruitIO_Dashboard();

  const char *name;
  const char *user();

  AdafruitIO *io();

  bool exists();
  bool create();

  ToggleBlock *addToggleBlock(AdafruitIO_Feed *feed);
  MomentaryBlock *addMomentaryBlock(AdafruitIO_Feed *feed);
  SliderBlock *addSliderBlock(AdafruitIO_Feed *feed);
  GaugeBlock *addGaugeBlock(AdafruitIO_Feed *feed);
  TextBlock *addTextBlock(AdafruitIO_Feed *feed);
  ChartBlock *addChartBlock(AdafruitIO_Feed *feed);
  ColorBlock *addColorBlock(AdafruitIO_Feed *feed);
  MapBlock *addMapBlock(AdafruitIO_Feed *feed);
  StreamBlock *addStreamBlock(AdafruitIO_Feed *feed);
  ImageBlock *addImageBlock(AdafruitIO_Feed *feed);

private:
  AdafruitIO *_io;
};

#endif // ADAFRUITIO_DASHBOARD_H
