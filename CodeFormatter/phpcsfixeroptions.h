#ifndef PHPCSFIXEROPTIONS_H
#define PHPCSFIXEROPTIONS_H

#include "cl_config.h" // Base class: clConfigItem

class PhpcsfixerOptions : public clConfigItem
{
    bool m_lintOnFileLoad;
    bool m_lintOnFileSave;
    wxString m_phpcsPhar;
    wxString m_phpmdPhar;
    wxString m_phpmdRules;

public:
    PhpcsfixerOptions();
    virtual ~PhpcsfixerOptions();

    virtual void FromJSON(const JSONElement& json);
    virtual JSONElement ToJSON() const;

    PhpcsfixerOptions& Load();
    PhpcsfixerOptions& Save();

    PhpcsfixerOptions& SetLintOnFileLoad(bool lintOnFileLoad)
    {
        this->m_lintOnFileLoad = lintOnFileLoad;
        return *this;
    }
    PhpcsfixerOptions& SetLintOnFileSave(bool lintOnFileSave)
    {
        this->m_lintOnFileSave = lintOnFileSave;
        return *this;
    }
    PhpcsfixerOptions& SetPhpcsPhar(const wxFileName& PhpcsPhar)
    {
        this->m_phpcsPhar = PhpcsPhar.GetFullPath();
        return *this;
    }
    PhpcsfixerOptions& SetPhpmdPhar(const wxFileName& PhpmdPhar)
    {
        this->m_phpmdPhar = PhpmdPhar.GetFullPath();
        return *this;
    }
    PhpcsfixerOptions& SetPhpmdRules(const wxFileName& PhpmdRules)
    {
        this->m_phpmdRules = PhpmdRules.GetFullPath();
        return *this;
    }

    bool IsLintOnFileLoad() const
    {
        return m_lintOnFileLoad;
    }
    bool IsLintOnFileSave() const
    {
        return m_lintOnFileSave;
    }
    const wxString& GetPhpcsPhar() const
    {
        return m_phpcsPhar;
    }
    const wxString& GetPhpmdPhar() const
    {
        return m_phpmdPhar;
    }
    const wxString& GetPhpmdRules() const
    {
        return m_phpmdRules;
    }
};

#endif // PHPCSFIXEROPTIONS_H
