�
 TFORM1 0t  TPF0TForm1Form1LeftsTop� Width�Height�CaptionForm1Color	clBtnFaceFont.CharsetDEFAULT_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameMS Sans Serif
Font.Style OldCreateOrderPositionpoScreenCenterPixelsPerInch`
TextHeight TPanelPanel1Left Top Width�HeightHAlignalClient
BevelOuter	bvLowered
BevelWidthBorderStylebsSingleTabOrder  TMemoMemo1LeftTopWidth�Height8AlignalClientFont.CharsetDEFAULT_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameMS Sans Serif
Font.StylefsBold Lines.StringsYThis program attempts to concatenate (join together) MTS video files.  It was created to Rsolve a problem with Canon HG10 files that are saved to ones hard disk.  The HG10 Zsplits files into 2GB pieces when recording for long periods of time.  When the files are Vbacked up to your computer's hard drive, the split ends are somehow not cleanly split Tbetween video and audio.  This creates an unacceptable loss of audio and video when ?you try to splice them back together using video editing tools. SYou start by selecting the files that you wish to join in to one contiguous file.   ?You then select the location and file name of the output file.  GA binary copy is performed in the creation of the new file.  Good luck!  
ParentFont
ScrollBarsssBothTabOrder    TPanelPanel2Left TopHWidth�Height=AlignalBottomBorderWidthBorderStylebsSingleTabOrder TBitBtnBitBtn1LeftTopWidthKHeightCaptionStartTabOrder OnClickBitBtn1ClickKindbkOK  TBitBtnBitBtn2LeftqTopWidthKHeightTabOrderOnClickBitBtn2ClickKindbkClose   TOpenDialogOpenDialog1
DefaultExtmtsFilter.mts Video File Format|*.mts
InitialDirMy DocumentsOptions
ofReadOnlyofOverwritePromptofAllowMultiSelectofPathMustExistofFileMustExistofEnableSizing Titlemts File Selection DialogLeft�Top  TOpenDialogOpenDialog2
DefaultExtmtsFiltermts Video Files|mts
InitialDirMy DocumentsOptionsofOverwritePromptofExtensionDifferentofPathMustExistofCreatePromptofEnableSizing TitleOutput File NameLeft�Top&   