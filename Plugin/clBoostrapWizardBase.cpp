//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: clBoostrapWizardBase.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "clBoostrapWizardBase.h"


// Declare the bitmap loading function
extern void wxCFAD6InitBitmapResources();

static bool bBitmapLoaded = false;


clBoostrapWizardBase::clBoostrapWizardBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxBitmap& bmp, const wxPoint& pos, long style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCFAD6InitBitmapResources();
        bBitmapLoaded = true;
    }
    Create(parent, id, title, wxNullBitmap, pos, style);
    
    m_wizardPageWelcome = new clBoostrapWizardPageWelcome(this, NULL, NULL, wxNullBitmap);
    m_pages.push_back(m_wizardPageWelcome);
    
    wxBoxSizer* boxSizer79 = new wxBoxSizer(wxVERTICAL);
    m_wizardPageWelcome->SetSizer(boxSizer79);
    
    m_banner81 = new wxBannerWindow(m_wizardPageWelcome, wxID_ANY, wxTOP, wxDefaultPosition, wxDLG_UNIT(m_wizardPageWelcome, wxSize(-1,-1)), 0);
    m_banner81->SetBitmap(wxNullBitmap);
    m_banner81->SetText(_("Welcome to the setup wizard"), _("This wizard will help you setup CodeLite to fit your coding style. Click Next to continue"));
    m_banner81->SetGradient(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE), wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));
    
    boxSizer79->Add(m_banner81, 0, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    wxBoxSizer* boxSizer105 = new wxBoxSizer(wxVERTICAL);
    
    boxSizer79->Add(boxSizer105, 1, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    boxSizer105->Add(0, 0, 1, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    m_cmdLnkBtn107 = new wxCommandLinkButton(m_wizardPageWelcome, wxID_ANY, _("Not this time!"), _("If your CodeLite is already configured the way you like it, click to skip the Wizard"), wxDefaultPosition, wxDLG_UNIT(m_wizardPageWelcome, wxSize(-1,-1)), 0);
    
    boxSizer105->Add(m_cmdLnkBtn107, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));
    
    boxSizer105->Add(0, 0, 1, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    m_wizardPagePlugins = new clBoostrapWizardPagePlugins(this, NULL, NULL, wxNullBitmap);
    m_pages.push_back(m_wizardPagePlugins);
    
    wxBoxSizer* boxSizer89 = new wxBoxSizer(wxVERTICAL);
    m_wizardPagePlugins->SetSizer(boxSizer89);
    
    m_banner811 = new wxBannerWindow(m_wizardPagePlugins, wxID_ANY, wxTOP, wxDefaultPosition, wxDLG_UNIT(m_wizardPagePlugins, wxSize(-1,-1)), 0);
    m_banner811->SetBitmap(wxNullBitmap);
    m_banner811->SetText(_("Development Profile"), _("Select the profile that best describes you"));
    m_banner811->SetGradient(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE), wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));
    
    boxSizer89->Add(m_banner811, 0, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    wxBoxSizer* boxSizer93 = new wxBoxSizer(wxHORIZONTAL);
    
    boxSizer89->Add(boxSizer93, 1, wxEXPAND, WXC_FROM_DIP(5));
    
    wxBoxSizer* boxSizer114 = new wxBoxSizer(wxVERTICAL);
    
    boxSizer93->Add(boxSizer114, 1, wxEXPAND, WXC_FROM_DIP(5));
    
    wxArrayString m_radioBoxProfileArr;
    m_radioBoxProfileArr.Add(_("Default (Don't change the current settings)"));
    m_radioBoxProfileArr.Add(_("Both C/C++ and Web development"));
    m_radioBoxProfileArr.Add(_("C/C++ development"));
    m_radioBoxProfileArr.Add(_("Web development (PHP, JS etc)"));
    m_radioBoxProfile = new wxRadioBox(m_wizardPagePlugins, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_wizardPagePlugins, wxSize(-1,-1)), m_radioBoxProfileArr, 1, wxRA_SPECIFY_COLS);
    m_radioBoxProfile->SetSelection(0);
    
    boxSizer114->Add(m_radioBoxProfile, 0, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    m_wizardPageCompilers = new clBoostrapWizardPageCompilers(this, NULL, NULL, wxNullBitmap);
    m_pages.push_back(m_wizardPageCompilers);
    
    wxBoxSizer* boxSizer52 = new wxBoxSizer(wxVERTICAL);
    m_wizardPageCompilers->SetSizer(boxSizer52);
    
    m_banner69 = new wxBannerWindow(m_wizardPageCompilers, wxID_ANY, wxTOP, wxDefaultPosition, wxDLG_UNIT(m_wizardPageCompilers, wxSize(-1,-1)), 0);
    m_banner69->SetBitmap(wxNullBitmap);
    m_banner69->SetText(_("Setup compilers"), _("Let CodeLite configure your installed compilers or help you install one"));
    m_banner69->SetGradient(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE), wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));
    
    boxSizer52->Add(m_banner69, 0, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    m_cmdLnkBtnScanForCompilers = new wxCommandLinkButton(m_wizardPageCompilers, wxID_ANY, _("Scan"), _("Click to scan your computer for installed compilers"), wxDefaultPosition, wxDLG_UNIT(m_wizardPageCompilers, wxSize(-1,-1)), 0);
    
    boxSizer52->Add(m_cmdLnkBtnScanForCompilers, 0, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    m_cmdLnkBtnDownloadCompiler = new wxCommandLinkButton(m_wizardPageCompilers, wxID_ANY, _("Install"), _("Click to download a MinGW compiler"), wxDefaultPosition, wxDLG_UNIT(m_wizardPageCompilers, wxSize(-1,-1)), 0);
    
    boxSizer52->Add(m_cmdLnkBtnDownloadCompiler, 0, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    m_dvListCtrlCompilers = new wxDataViewListCtrl(m_wizardPageCompilers, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_wizardPageCompilers, wxSize(-1,-1)), wxDV_VERT_RULES|wxDV_ROW_LINES|wxDV_SINGLE);
    m_dvListCtrlCompilers->Hide();
    
    boxSizer52->Add(m_dvListCtrlCompilers, 1, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    m_dvListCtrlCompilers->AppendTextColumn(_("Compiler Name"), wxDATAVIEW_CELL_INERT, WXC_FROM_DIP(150), wxALIGN_LEFT, wxDATAVIEW_COL_RESIZABLE);
    m_dvListCtrlCompilers->AppendTextColumn(_("Installation Path"), wxDATAVIEW_CELL_INERT, WXC_FROM_DIP(-2), wxALIGN_LEFT, wxDATAVIEW_COL_RESIZABLE);
    m_wizardPageColoursAndFonts = new clBoostrapWizardPageColours(this, NULL, NULL, wxNullBitmap);
    m_pages.push_back(m_wizardPageColoursAndFonts);
    
    wxBoxSizer* boxSizer12 = new wxBoxSizer(wxVERTICAL);
    m_wizardPageColoursAndFonts->SetSizer(boxSizer12);
    
    m_banner71 = new wxBannerWindow(m_wizardPageColoursAndFonts, wxID_ANY, wxTOP, wxDefaultPosition, wxDLG_UNIT(m_wizardPageColoursAndFonts, wxSize(-1,-1)), 0);
    m_banner71->SetBitmap(wxNullBitmap);
    m_banner71->SetText(_("Customize colours"), _("Select the editor theme from the list below"));
    m_banner71->SetGradient(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE), wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));
    
    boxSizer12->Add(m_banner71, 0, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    wxArrayString m_choiceThemeArr;
    m_choiceTheme = new wxChoice(m_wizardPageColoursAndFonts, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_wizardPageColoursAndFonts, wxSize(-1,-1)), m_choiceThemeArr, wxBORDER_NONE);
    m_choiceTheme->SetToolTip(_("Select the theme from a list.\nIf the selected theme does not exist for a given language, CodeLite will select the closest one available"));
    m_choiceTheme->SetFocus();
    
    boxSizer12->Add(m_choiceTheme, 0, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    m_stc24 = new wxStyledTextCtrl(m_wizardPageColoursAndFonts, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_wizardPageColoursAndFonts, wxSize(-1,-1)), 0);
    // Configure the fold margin
    m_stc24->SetMarginType     (4, wxSTC_MARGIN_SYMBOL);
    m_stc24->SetMarginMask     (4, wxSTC_MASK_FOLDERS);
    m_stc24->SetMarginSensitive(4, true);
    m_stc24->SetMarginWidth    (4, 16);
    
    m_stc24->SetProperty(wxT("fold"),wxT("1"));
    m_stc24->MarkerDefine(wxSTC_MARKNUM_FOLDEROPEN,    wxSTC_MARK_ARROWDOWN);
    m_stc24->MarkerDefine(wxSTC_MARKNUM_FOLDER,        wxSTC_MARK_ARROW);
    m_stc24->MarkerDefine(wxSTC_MARKNUM_FOLDERSUB,     wxSTC_MARK_BACKGROUND);
    m_stc24->MarkerDefine(wxSTC_MARKNUM_FOLDERTAIL,    wxSTC_MARK_BACKGROUND);
    m_stc24->MarkerDefine(wxSTC_MARKNUM_FOLDEREND,     wxSTC_MARK_ARROW);
    m_stc24->MarkerDefine(wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_ARROWDOWN);
    m_stc24->MarkerDefine(wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_BACKGROUND);
    // Configure the tracker margin
    m_stc24->SetMarginWidth(1, 0);
    
    // Configure the symbol margin
    m_stc24->SetMarginType (2, wxSTC_MARGIN_SYMBOL);
    m_stc24->SetMarginMask (2, ~(wxSTC_MASK_FOLDERS));
    m_stc24->SetMarginWidth(2, 0);
    m_stc24->SetMarginSensitive(2, true);
    
    // Configure the line numbers margin
    int m_stc24_PixelWidth = 4 + 5 *m_stc24->TextWidth(wxSTC_STYLE_LINENUMBER, wxT("9"));
    m_stc24->SetMarginType(0, wxSTC_MARGIN_NUMBER);
    m_stc24->SetMarginWidth(0,m_stc24_PixelWidth);
    
    // Configure the line symbol margin
    m_stc24->SetMarginType(3, wxSTC_MARGIN_FORE);
    m_stc24->SetMarginMask(3, 0);
    m_stc24->SetMarginWidth(3,0);
    // Select the lexer
    m_stc24->SetLexer(wxSTC_LEX_NULL);
    // Set default font / styles
    m_stc24->StyleClearAll();
    m_stc24->SetWrapMode(0);
    m_stc24->SetIndentationGuides(0);
    m_stc24->SetKeyWords(0, wxT(""));
    m_stc24->SetKeyWords(1, wxT(""));
    m_stc24->SetKeyWords(2, wxT(""));
    m_stc24->SetKeyWords(3, wxT(""));
    m_stc24->SetKeyWords(4, wxT(""));
    
    boxSizer12->Add(m_stc24, 1, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    m_wizardPageWhitespace = new clBoostrapWizardPageWhitespace(this, NULL, NULL, wxNullBitmap);
    m_pages.push_back(m_wizardPageWhitespace);
    if (m_pages.size() > 1) {
        for(size_t i=1; i<m_pages.size(); i++) {
            wxWizardPageSimple::Chain(m_pages.at(i-1), m_pages.at(i));
        }
    }
    GetPageAreaSizer()->Add(m_pages.at(0));
    
    wxBoxSizer* boxSizer30 = new wxBoxSizer(wxVERTICAL);
    m_wizardPageWhitespace->SetSizer(boxSizer30);
    
    m_banner73 = new wxBannerWindow(m_wizardPageWhitespace, wxID_ANY, wxTOP, wxDefaultPosition, wxDLG_UNIT(m_wizardPageWhitespace, wxSize(-1,-1)), 0);
    m_banner73->SetBitmap(wxNullBitmap);
    m_banner73->SetText(_("Whitespace & Indentation"), _("Should CodeLite use TABS or SPACES for indentation?"));
    m_banner73->SetGradient(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE), wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));
    
    boxSizer30->Add(m_banner73, 0, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    boxSizer30->Add(0, 0, 1, wxALL, WXC_FROM_DIP(5));
    
    wxArrayString m_radioBoxSpacesVsTabsArr;
    m_radioBoxSpacesVsTabsArr.Add(_("Indent using SPACES"));
    m_radioBoxSpacesVsTabsArr.Add(_("Indent using TABS"));
    m_radioBoxSpacesVsTabs = new wxRadioBox(m_wizardPageWhitespace, wxID_ANY, _("Indentation"), wxDefaultPosition, wxDLG_UNIT(m_wizardPageWhitespace, wxSize(200,-1)), m_radioBoxSpacesVsTabsArr, 1, wxRA_SPECIFY_COLS);
    m_radioBoxSpacesVsTabs->SetSelection(0);
    
    boxSizer30->Add(m_radioBoxSpacesVsTabs, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));
    
    wxArrayString m_radioBoxWhitespaceVisibilityArr;
    m_radioBoxWhitespaceVisibilityArr.Add(_("Invisible"));
    m_radioBoxWhitespaceVisibilityArr.Add(_("Visible always"));
    m_radioBoxWhitespaceVisibilityArr.Add(_("Visible after indentation"));
    m_radioBoxWhitespaceVisibility = new wxRadioBox(m_wizardPageWhitespace, wxID_ANY, _("Whitespace Visibility:"), wxDefaultPosition, wxDLG_UNIT(m_wizardPageWhitespace, wxSize(200,-1)), m_radioBoxWhitespaceVisibilityArr, 1, wxRA_SPECIFY_COLS);
    m_radioBoxWhitespaceVisibility->SetSelection(1);
    
    boxSizer30->Add(m_radioBoxWhitespaceVisibility, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));
    
    boxSizer30->Add(0, 0, 1, wxALL, WXC_FROM_DIP(5));
    
    SetName(wxT("clBoostrapWizardBase"));
    SetSize(-1,-1);
    if (GetSizer()) {
         GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
    // Connect events
    this->Connect(wxEVT_WIZARD_FINISHED, wxWizardEventHandler(clBoostrapWizardBase::OnFinish), NULL, this);
    m_cmdLnkBtn107->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(clBoostrapWizardBase::OnCancelWizard), NULL, this);
    m_cmdLnkBtnScanForCompilers->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(clBoostrapWizardBase::OnScanForCompilers), NULL, this);
    m_cmdLnkBtnDownloadCompiler->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(clBoostrapWizardBase::OnInstallCompilerUI), NULL, this);
    m_cmdLnkBtnDownloadCompiler->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(clBoostrapWizardBase::OnInstallCompiler), NULL, this);
    m_choiceTheme->Connect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(clBoostrapWizardBase::OnThemeSelected), NULL, this);
    
}

clBoostrapWizardBase::~clBoostrapWizardBase()
{
    this->Disconnect(wxEVT_WIZARD_FINISHED, wxWizardEventHandler(clBoostrapWizardBase::OnFinish), NULL, this);
    m_cmdLnkBtn107->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(clBoostrapWizardBase::OnCancelWizard), NULL, this);
    m_cmdLnkBtnScanForCompilers->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(clBoostrapWizardBase::OnScanForCompilers), NULL, this);
    m_cmdLnkBtnDownloadCompiler->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(clBoostrapWizardBase::OnInstallCompilerUI), NULL, this);
    m_cmdLnkBtnDownloadCompiler->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(clBoostrapWizardBase::OnInstallCompiler), NULL, this);
    m_choiceTheme->Disconnect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(clBoostrapWizardBase::OnThemeSelected), NULL, this);
    
}
