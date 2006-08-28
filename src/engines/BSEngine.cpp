/**********************************************************************
  BSEngine - Engine for "balls and sticks" display

  Copyright (C) 2006 by Geoffrey R. Hutchison
  Some portions Copyright (C) 2006 by Donald E. Curtis

  This file is part of the Avogadro molecular editor project.
  For more information, see <http://avogadro.sourceforge.net/>

  Some code is based on Open Babel
  For more information, see <http://openbabel.sourceforge.net/>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation version 2 of the License.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
 ***********************************************************************/

#include "BSEngine.h"
#include "Primitives.h"
#include <openbabel/obiter.h>

#include <QtGui>

using namespace std;
using namespace OpenBabel;
using namespace Avogadro;

void BSEngine::render(Atom *atom)
{
  // cout << "Render Atom..." << endl;
  if (!m_sphere.isValid())
    m_sphere.setup(3);

  glDisable( GL_NORMALIZE );
  glEnable( GL_RESCALE_NORMAL );

  //  Color(atom).applyAsMaterials();
  std::vector<double> rgb;
  rgb = etab.GetRGB(atom->GetAtomicNum());
  glColor3d(rgb[0], rgb[1], rgb[2]);

  m_sphere.draw(atom->GetVector(), etab.GetVdwRad(atom->GetAtomicNum()) * 0.3);
  glEnable( GL_NORMALIZE );
  glDisable( GL_RESCALE_NORMAL );
}

void BSEngine::render(Bond *b)
{
  // cout << "Render Bond..." << endl;
  if (!m_cylinder.isValid())
    m_cylinder.setup(6);

  glDisable( GL_NORMALIZE );
  glEnable( GL_RESCALE_NORMAL );

  OBAtom *atom1 = static_cast<OBAtom *>( b->GetBgn() );
  OBAtom *atom2 = static_cast<OBAtom *>( b->GetEnd() );
  
  vector3 v1 = atom1->GetVector();
  vector3 v2 = atom2->GetVector();
  vector3 v3 = ( v1 + v2 ) / 2;
  std::vector<double> rgb;

  double radius = 0.1;
  double shift = 0.15;
  int order = b->GetBO();

  glLoadName( atom1->GetIdx() );
  rgb = etab.GetRGB(atom1->GetAtomicNum());
  glColor3d(rgb[0], rgb[1], rgb[2]);
  m_cylinder.draw( v1, v3, radius, order, shift);
  glLoadName( atom2->GetIdx() );
  rgb = etab.GetRGB(atom2->GetAtomicNum());
  glColor3d(rgb[0], rgb[1], rgb[2]);
  m_cylinder.draw( v2, v3, radius, order, shift);

  glEnable( GL_NORMALIZE );
  glDisable( GL_RESCALE_NORMAL );
}

Q_EXPORT_PLUGIN2(BSEngine, BSEngineFactory)
