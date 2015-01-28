/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtQuick module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef FRICTIONAFFECTOR_H
#define FRICTIONAFFECTOR_H
#include "qquickparticleaffector_p.h"

QT_BEGIN_NAMESPACE

class QQuickFrictionAffector : public QQuickParticleAffector
{
    Q_OBJECT
    Q_PROPERTY(qreal factor READ factor WRITE setFactor NOTIFY factorChanged)
    Q_PROPERTY(qreal threshold READ threshold WRITE setThreshold NOTIFY thresholdChanged)
public:
    explicit QQuickFrictionAffector(QQuickItem *parent = 0);

    qreal factor() const
    {
        return m_factor;
    }

    qreal threshold() const
    {
        return m_threshold;
    }

protected:
    virtual bool affectParticle(QQuickParticleData *d, qreal dt);

Q_SIGNALS:

    void factorChanged(qreal arg);
    void thresholdChanged(qreal arg);

public Q_SLOTS:

    void setFactor(qreal arg)
    {
        if (m_factor != arg) {
            m_factor = arg;
            Q_EMIT factorChanged(arg);
        }
    }

    void setThreshold(qreal arg)
    {
        if (m_threshold != arg) {
            m_threshold = arg;
            Q_EMIT thresholdChanged(arg);
        }
    }

private:
    qreal m_factor;
    qreal m_threshold;
};

QT_END_NAMESPACE
#endif // FRICTIONAFFECTOR_H