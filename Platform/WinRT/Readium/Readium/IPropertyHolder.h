//
//  IPropertyHolder.h
//  Readium
//
//  Created by Jim Dovey on 2013-09-26.
//  Copyright (c) 2012-2013 The Readium Foundation and contributors.
//  
//  The Readium SDK is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef __Readium_IPropertyHolder_h__
#define __Readium_IPropertyHolder_h__

#include "Readium.h"
#include "WinProperty.h"
#include <collection.h>

BEGIN_READIUM_API

using namespace ::Platform;
using namespace ::Platform::Collections;
using namespace ::Windows::Foundation;
using namespace ::Windows::Foundation::Collections;

/// Enumerated constants for the DCMES metadata attributes used by EPUB 3.
public enum class DCType
{
	Invalid,        ///< An invalid value.

	// Required DCMES Elements.
	
	/// A unique identifier.
	Identifier,
	/// The title of the publication.
	Title,
	/// The language in which the publication is rendered.
	Language,

	// Optional DCMES elements

	/// The name of a secondary contributor.
	Contributor,
	/// Spatial or temporal context of the publication.
	Coverage,
	/// The name of a primary creator.
	Creator,
	/// The original publication date (*not* the modification date).
	Date,
	/// A description of the publication's contents.
	Description,
	/// Information on the format in which the publication is rendered.
	Format,
    /// Details of the publisher of the work.
	Publisher,
	/// An identifier for a related resource.
	Relation,
	/// Information about rights associated with the publication.
	Rights,
	/// An identifier for the source of this EPUB, e.g. the ISBN of an original print edition.
	Source,
	/// The topic or topics which form the subject of the publication.
	Subject,
	/// The type of content encoded in this publication, e.g. book, annotations, minutes, etc.
	Type,

	/// A non-DCMES metadata value, identified only by its property IRI.
	Custom = UCHAR_MAX
};

/// Enumeration for page spreads.
public enum class PageSpread
{
	/// No value specified by the author.
	Automatic,
	/// This is the left page of a spread.
	Left,
	/// This is the right page of a spread.
	Right,
	/// This is a double-width page, spread across both left & right.
	Center,
};

/// Enumeration for page progression directions.
public enum class PageProgression
{
	/// Assume based on language, etc.
	Default,
	/// Pages flow from left to right, as in English.
	LeftToRight,
	/// Pages flow from right to left, as in Japanese comics & vertical text.
	RightToLeft,
};

public interface class IPropertyHolder : IIterable<Property^>
{
	property unsigned int Count { unsigned int get(); }

	[::Windows::Foundation::Metadata::DefaultOverload]
	void Append(Property^ prop);
	void Append(IPropertyHolder^ allProps);

	[::Windows::Foundation::Metadata::DefaultOverload]
	void Remove(Uri^ propertyIRI);
	void Remove(String^ reference);
	void Remove(String^ prefix, String^ reference);

	Property^ At(unsigned int idx);
	void EraseAt(unsigned int idx);

	bool Contains(DCType type);
	[::Windows::Foundation::Metadata::DefaultOverload]
	bool Contains(Uri^ propertyIRI);
	bool Contains(String^ reference);
	bool Contains(String^ prefix, String^ reference);

	Property^ PropertyMatching(DCType type);
	[::Windows::Foundation::Metadata::DefaultOverload]
	Property^ PropertyMatching(Uri^ propertyIRI);
	Property^ PropertyMatching(String^ reference);
	Property^ PropertyMatching(String^ prefix, String^ reference);

	IVectorView<Property^>^ PropertiesMatching(DCType type);
	[::Windows::Foundation::Metadata::DefaultOverload]
	IVectorView<Property^>^ PropertiesMatching(Uri^ propertyIRI);
	IVectorView<Property^>^ PropertiesMatching(String^ reference);
	IVectorView<Property^>^ PropertiesMatching(String^ prefix, String^ reference);

	void RegisterPrefixIRIStem(String^ prefix, String^ iriStem);
	
	Uri^ MakePropertyIRI(String^ reference);
	Uri^ MakePropertyIRI(String^ prefix, String^ reference);
	Uri^ PropertyIRIFromString(String^ str);

};

END_READIUM_API

#endif	/* __Readium_IPropertyHolder_h__ */
