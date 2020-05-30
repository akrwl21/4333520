/*=========================================================================
    2
    3   Program:   Visualization Toolkit
    4   Module:    QVTKInteractor.h
    5
    6   Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
    7   All rights reserved.
    8   See Copyright.txt or http://www.kitware.com/Copyright.htm for details.
    9
   10      This software is distributed WITHOUT ANY WARRANTY; without even
   11      the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
   12      PURPOSE.  See the above copyright notice for more information.
   13
   14 =========================================================================*/
   15
   16 /*=========================================================================
   17
   18   Copyright 2004 Sandia Corporation.
   19   Under the terms of Contract DE-AC04-94AL85000, there is a non-exclusive
   20   license for use of this work by or on behalf of the
   21   U.S. Government. Redistribution and use in source and binary forms, with
   22   or without modification, are permitted provided that this Notice and any
   23   statement of authorship are reproduced on all copies.
   24
   25 =========================================================================*/
   26
   27 #ifndef Q_VTK_INTERACTOR_H
   28 #define Q_VTK_INTERACTOR_H
   29
   30 #include "QVTKWin32Header.h"
   31 #include "vtkGUISupportQtModule.h" // For export macro
   32 #include <QtCore/QObject>
   33 #include <vtkCommand.h>
   34 #include <vtkRenderWindowInteractor.h>
   35
   36 #include "vtkTDxConfigure.h" // defines VTK_USE_TDX
   37 #if defined(VTK_USE_TDX) && defined(Q_OS_WIN)
   38 class vtkTDxWinDevice;
   39 #endif
   40 #if defined(VTK_USE_TDX) && defined(Q_OS_MAC)
   41 class vtkTDxMacDevice;
   42 #endif
   43 #if defined(VTK_USE_TDX) && (defined(Q_WS_X11) || defined(Q_OS_LINUX))
   44 class vtkTDxDevice;
   45 class vtkTDxUnixDevice;
   46 #endif
   47
   48 class QVTKInteractorInternal;
   49
   58 class VTKGUISUPPORTQT_EXPORT QVTKInteractor : public vtkRenderWindowInteractor
   59 {
   60 public:
   61   static QVTKInteractor* New();
   62   vtkTypeMacro(QVTKInteractor, vtkRenderWindowInteractor);
   63
   68   enum vtkCustomEvents
   69   {
   70     ContextMenuEvent = vtkCommand::UserEvent + 100,
   71     DragEnterEvent,
   72     DragMoveEvent,
   73     DragLeaveEvent,
   74     DropEvent
   75   };
   76
   81   void TerminateApp() override;
   82
   87   void Start() override;
   88   void Initialize() override;
   89
   93   virtual void StartListening();
   94
   98   virtual void StopListening();
   99
  103   virtual void TimerEvent(int timerId);
  104
  105 #if defined(VTK_USE_TDX) && (defined(Q_WS_X11) || defined(Q_OS_LINUX))
  106   virtual vtkTDxUnixDevice* GetDevice();
  107   virtual void SetDevice(vtkTDxDevice* device);
  108 #endif
  109
  110 protected:
  111   // constructor
  112   QVTKInteractor();
  113   // destructor
  114   ~QVTKInteractor() override;
  115
  116   // create a Qt Timer
  117   int InternalCreateTimer(int timerId, int timerType, unsigned long duration) override;
  118   // destroy a Qt Timer
  119   int InternalDestroyTimer(int platformTimerId) override;
  120 #if defined(VTK_USE_TDX) && defined(Q_OS_WIN)
  121   vtkTDxWinDevice* Device;
  122 #endif
  123 #if defined(VTK_USE_TDX) && defined(Q_OS_MAC)
  124   vtkTDxMacDevice* Device;
  125 #endif
  126 #if defined(VTK_USE_TDX) && (defined(Q_WS_X11) || defined(Q_OS_LINUX))
  127   vtkTDxUnixDevice* Device;
  128 #endif
  129
  130 private:
  131   QVTKInteractorInternal* Internal;
  132
  133   QVTKInteractor(const QVTKInteractor&) = delete;
  134   void operator=(const QVTKInteractor&) = delete;
  135 };
  136
  137 #endif
